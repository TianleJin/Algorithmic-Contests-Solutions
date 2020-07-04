class TreeNode:
    def __init__(self, key=None, val=None):
        self.key = key
        self.val = val
        self.left = None
        self.right = None
    
    def is_leaf(self):
        return self.left is None and self.right is None


class BinarySearchTree:
    def __init__(self):
        self.root = None
    
    def traverse(self):
        def dfs(root):
            if root:
                dfs(root.left)
                print(root.key, root.val)
                dfs(root.right)
        dfs(self.root)
    
    def __getitem__(self, key):
        def search(root):
            if not root:
                return False
            elif root.key == key:
                return root.val
            elif root.key > key:
                return search(root.left)
            else:
                return search(root.right)
        return search(self.root)
    
    def __setitem__(self, key, val):
        if not self.root:
            self.root = TreeNode(key, val)
            return

        def search(root):
            if root.key == key:
                root.val = val
            elif root.key > key:
                if not root.left:
                    root.left = TreeNode(key, val)
                else:
                    search(root.left)
            else:
                if not root.right:
                    root.right = TreeNode(key, val)
                else:
                    search(root.right)
        search(self.root)
    
    def __delitem__(self, key):
        def successor(root):
            curr = root.right
            while curr.left:
                curr = curr.left
            return curr
            
        def search(root, key):
            if root is None:
                return root
            elif key < root.key:
                root.left = search(root.left, key)
            elif key > root.key:
                root.right = search(root.right, key)
            else:
                if root.left is None:
                    temp = root.right
                    root = None
                    return temp
                if root.right is None:
                    temp = root.left
                    root = None
                    return temp
                temp = successor(root)
                root.key, root.val = temp.key, temp.val
                root.right = search(root.right, temp.key)
            return root
        self.root = search(self.root, key)