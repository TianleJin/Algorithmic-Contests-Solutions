class minHeap:

    def __init__(self, arr):
        self.size = len(arr)
        self.heap = [0] + arr
        self.heapify()

    def check(self):
        ok = True
        for idx in range(self.size, 0, -1):
            if idx << 1 <= self.size and self.heap[idx] > self.heap[idx << 1]:
                ok = False
            if idx << 1 | 1 <= self.size and self.heap[idx] > self.heap[idx << 1 | 1]:
                ok = False
        return ok

    def isEmpty(self):
        return self.size == 0

    def getChild(self, idx):
        if idx << 1 | 1 <= self.size:
            return idx << 1 if self.heap[idx << 1] <= self.heap[idx << 1 | 1] else idx << 1 | 1
        elif idx << 1 <= self.size:
            return idx << 1
        else:
            raise KeyError

    def sink(self, idx):
        while 2 * idx <= self.size:
            child = self.getChild(idx)
            if self.heap[idx] <= self.heap[child]:
                break
            self.heap[idx], self.heap[child] = self.heap[child], self.heap[idx]
            idx = child

    def rise(self, idx):
        while idx > 1:
            parent = idx >> 1
            if self.heap[idx] >= self.heap[parent]:
                break
            self.heap[idx], self.heap[parent] = self.heap[parent], self.heap[idx]
            idx = parent

    def heapify(self):
        for idx in range(self.size >> 1, 0, -1):
            self.sink(idx)

    def heappop(self):
        if self.isEmpty():
            raise ValueError

        self.heap[1], self.heap[self.size] = self.heap[self.size], self.heap[1]
        self.size -= 1
        self.sink(1)
        return self.heap.pop()

    def heappush(self, val):
        self.heap.append(val)
        self.size += 1
        self.rise(self.size)
    
    def peak(self):
        if self.isEmpty():
            raise ValueError
        return self.heap[1]
