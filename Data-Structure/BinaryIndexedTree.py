class BinaryIndexedTree:
    
    def __init__(self, arr):
        self.arr = arr
        self.size = len(arr)
        self.tree = [0] * (self.size + 1)
        self.build()
    
    def build(self):
        for idx, val in enumerate(self.arr):
            self.propagate(idx, val)
    
    def update(self, idx, val):
        if self.check(idx):
            delta = val - self.arr[idx]
            self.arr[idx] = val
            self.propagate(idx, delta)

    def query(self, lo, hi):
        if self.check(lo) and self.check(hi): 
            return self.prefix(hi) - self.prefix(lo - 1)

    def prefix(self, idx):
        idx += 1
        ans = 0
        while idx > 0:
            ans += self.tree[idx]
            idx -= idx & (-idx)
        return ans

    def propagate(self, idx, delta):
        idx += 1
        while idx <= self.size:
            self.tree[idx] += delta
            idx += idx & (-idx)

    def check(self, idx):
        return 0 <= idx < self.size