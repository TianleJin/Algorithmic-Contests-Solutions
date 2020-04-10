class TreeNode:

    def __init__(self, val, lo, hi):
        self.val = val
        self.lo = lo
        self.hi = hi
        self.left = None
        self.right = None


class SumSegmentTree:

    def __init__(self, arr):
        self.n = len(arr)
        self.root = self.build(arr, 0, self.n - 1)
    
    def build(self, arr, lo, hi):
        if lo == hi:
            return TreeNode(arr[lo], lo, hi)
        mid = (lo + hi) >> 1
        left_child = self.build(arr, lo, mid)
        right_child = self.build(arr, mid + 1, hi)
        root = TreeNode(left_child.val + right_child.val, lo, hi)
        root.left = left_child
        root.right = right_child
        return root
    
    def update(self, idx, val):
        def search(root):
            if root.lo == root.hi:
                root.val = val
                return
            mid = (root.lo + root.hi) >> 1
            if idx <= mid:
                root.val -= root.left.val
                search(root.left)
                root.val += root.left.val
            else:
                root.val -= root.right.val
                search(root.right)
                root.val += root.right.val
        search(self.root)

    def query(self, lo, hi):
        def tally(root, lo, hi):
            if root.lo == lo and root.hi == hi:
                return root.val
            mid = (root.lo + root.hi) >> 1
            if lo > mid:
                return tally(root.right, lo, hi)
            elif hi <= mid:
                return tally(root.left, lo, hi)
            else:
                return tally(root.left, lo, mid) + tally(root.right, mid + 1, hi)
        return tally(self.root, lo, hi) 