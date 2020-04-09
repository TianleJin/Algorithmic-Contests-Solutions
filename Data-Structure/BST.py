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
                print(root.key, root.val)
                dfs(root.left)
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
            return True

        def search(root):
            if not root:
                return False
            elif root.key == key:
                root.val = val
                return True
            elif root.key > key:
                if not search(root.left):
                    root.left = TreeNode(key, val)
                return True
            else:
                if not search(root.right):
                    root.right = TreeNode(key, val)
                return True
        return search(self.root)
    
    def __delitem__(self, key):
        targets = []

        def search(par, root):
            if not root:
                return False 
            elif root.key == key:
                print('found')
                targets.append(root)
                targets.append(par)
                return True
            elif root.key > key:
                return search(root, root.left)
            else:
                return search(root, root.right)

        def find_successor(node):
            curr = node.right
            while curr.left:
                curr = curr.left
            return curr
        
        # node is not in tree
        if not search(None, self.root):
            raise KeyError
        
        node = targets[0]
        parent = targets[1]

        # leaf node
        if node.is_leaf():
            print('leaf')
            if parent is None:
                self.root = None
            elif parent.left is node:
                parent.left = None
            else:
                parent.right = None
            
        # single child
        elif node.left is None or node.right is None:
            print('single')
            if node.left:
                child = node.left
                node.left = None
            else:
                child = node.right
                node.right = None

            if parent is None:
                self.root = child
            elif parent.left is node:
                parent.left = child
            else:
                parent.right = child
        
        # two children
        else:
            print('double')
            successor = find_successor(node)
            tmp_key, tmp_val = successor.key, successor.val
            self.__delitem__(successor.key)
            node.key, node.val = tmp_key, tmp_val

        return True


if __name__ == "__main__":
    bst = BinarySearchTree()
    for k, v in zip(range(9), 'abcdefghi'):
        bst[k] = v
    del bst[0]
    del bst[3]
    bst.traverse()