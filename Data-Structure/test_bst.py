import unittest
from random import randint
from BinarySearchTree import BinarySearchTree


class testBST(unittest.TestCase):
    def case(self, ub):
        n = randint(1, ub)
        return {randint(-10000, 10000): randint(-1000, 1000) for _ in range(n)}

    def test_general(self):
        # small case
        t1 = BinarySearchTree()
        mapping = {
            10: 0,
            1: 1,
            2: 2,
            18: 3, 
            9: 4,
            11: 5,
            13: 6,
            3: 7
        }
        for key, val in mapping.items():
            t1[key] = val
        
        for key, val in mapping.items():
            self.assertEqual(t1[key], val)
        
        # delete leaf node
        del t1[13]
        for key, val in mapping.items():
            if key == 13:
                self.assertFalse(t1[key])
            else:
                self.assertEqual(t1[key], val)

        # delete node with two child
        del t1[10]
        for key, val in mapping.items():
            if key in (10, 13):
                self.assertFalse(t1[key])
            else:
                self.assertEqual(t1[key], val)

        # delete node with one child
        del t1[1]
        for key, val in mapping.items():
            if key in (1, 10, 13):
                self.assertFalse(t1[key])
            else:
                self.assertEqual(t1[key], val)

        # medium case
        ub = 50
        for _ in range(100):
            D = set()
            B = self.case(ub)
            t = BinarySearchTree()

            # newly inserted values
            for key, val in B.items():
                t[key] = val
            
            for key, val in B.items():
                self.assertEqual(t[key], val)
            
            # modified values
            for key in B:
                B[key] = randint(-1000, -1000)
                t[key] = B[key]
            
            for key, val in B.items():
                self.assertEqual(t[key], val)
            
            # insert some more new values
            I = self.case(ub)
            for key, val in I.items():
                t[key] = val
                B[key] = val
            
            for key, val in B.items():
                self.assertEqual(t[key], val)
            
            # delete values one by one
            for key, val in B.items():
                del t[key]
                D.add(key)
                for key, val in B.items():
                    if key in D:
                        self.assertFalse(t[key])
                    else:
                        self.assertEqual(t[key], val)
            self.assertEqual(t.root, None)

if __name__ == '__main__':
    unittest.main()