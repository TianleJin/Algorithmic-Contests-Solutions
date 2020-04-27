import unittest
from random import randint
from PrefixArray import PrefixArray
from SegmentTree import SumSegmentTree
from BinaryIndexedTree import BinaryIndexedTree


class TestPrefixSum(unittest.TestCase):

    def gen_case(self, size, ub=100):
        return [randint(-ub, ub) for _ in range(size)]

    def gen_query(self, size):
        lo = randint(0, size - 1)
        hi = randint(lo, size - 1)
        return lo, hi
    
    def gen_update(self, size, ub=100):
        return randint(0, size - 1), randint(-ub, ub)

    def test_query(self, test_iter=100, test_len=100, n_query=1000):
        for _ in range(test_iter):
            test_size = randint(2, test_len)
            test_case = self.gen_case(test_size)

            par = PrefixArray(test_case[:])
            sgt = SumSegmentTree(test_case[:])
            bit = BinaryIndexedTree(test_case[:])
            
            for _ in range(n_query):
                lo, hi = self.gen_query(test_size)
                par_ans = par.query(lo, hi)
                sgt_ans = sgt.query(lo, hi)
                bit_ans = bit.query(lo, hi)
                self.assertTrue(par_ans == sgt_ans and sgt_ans == bit_ans)
    
    def test_update(self, test_iter=100, test_len=100, n_update=100):
        for _ in range(test_iter):
            test_size = randint(2, test_len)
            test_case = self.gen_case(test_size)

            par = PrefixArray(test_case[:])
            sgt = SumSegmentTree(test_case[:])
            bit = BinaryIndexedTree(test_case[:])
        
            for _ in range(n_update):
                idx, val = self.gen_update(test_size)
                par.update(idx, val)
                sgt.update(idx, val)
                bit.update(idx, val)

            lo, hi = self.gen_query(test_size)
            par_ans = par.query(lo, hi)
            sgt_ans = sgt.query(lo, hi)
            bit_ans = bit.query(lo, hi)
            self.assertTrue(par_ans == sgt_ans and sgt_ans == bit_ans)


if __name__ == '__main__':
    unittest.main()