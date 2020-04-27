class PrefixArray:

    def __init__(self, arr):
        self.arr = arr
        self.size = len(arr)
        self.prefix = [0] * (self.size + 1)
        self.build()

    def build(self):
        for idx, val in enumerate(self.arr):
            self.prefix[idx + 1] = self.prefix[idx] + val
    
    def update(self, idx, val):
        delta = val - self.arr[idx]
        self.arr[idx] = val
        for i in range(idx + 1, self.size + 1):
            self.prefix[i] += delta
    
    def query(self, lo, hi):
        return self.prefix[hi + 1] - self.prefix[lo]