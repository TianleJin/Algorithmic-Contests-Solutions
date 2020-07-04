import unittest
from random import randint
from minHeap import minHeap


class testMinHeap(unittest.TestCase):

    def case(self, ub):
        s = randint(1, ub)
        return [randint(-1000, 1000) for _ in range(s)]

    def test_heapify(self):
        # trivial case 
        my_heap = minHeap([])
        my_heap.heapify()
        self.assertEqual(my_heap.heap, [0])
        self.assertTrue(my_heap.check())
        self.assertTrue(my_heap.isEmpty())

        # tiny case
        my_heap = minHeap([1, 0])
        my_heap.heapify()
        self.assertEqual(my_heap.heap, [0, 0, 1])
        self.assertTrue(my_heap.check())
        self.assertFalse(my_heap.isEmpty())

        # small case
        my_heap = minHeap([4, 3, 2, 1])
        my_heap.heapify()
        self.assertEqual(my_heap.heap, [0, 1, 3, 2, 4])
        self.assertTrue(my_heap.check())
        self.assertFalse(my_heap.isEmpty())

        # small case
        my_heap = minHeap([5, 4, 3, 2, 1])
        my_heap.heapify()
        self.assertEqual(my_heap.heap, [0, 1, 2, 3, 5, 4])
        self.assertTrue(my_heap.check())
        self.assertFalse(my_heap.isEmpty())

        # medium cases
        ub = 50
        for _ in range(100):
            my_heap = minHeap(self.case(ub))
            self.assertTrue(my_heap.check())
        
        # large cases
        ub = 1000
        for _ in range(50):
            my_heap = minHeap(self.case(ub))
            self.assertTrue(my_heap.check())

        # giant cases
        ub = 10000
        for _ in range(10):
            my_heap = minHeap(self.case(ub))
            self.assertTrue(my_heap.check())

    def test_heappush(self):
        # small cases
        ub = 10
        for _ in range(500):
            A = self.case(ub)
            N = self.case(ub)
            my_heap = minHeap(A)
            for val in N:
                my_heap.heappush(val)
                self.assertTrue(my_heap.check())
        
        # medium cases
        ub = 50
        for _ in range(100):
            A = self.case(ub)
            N = self.case(ub)
            my_heap = minHeap(A)
            for val in N:
                my_heap.heappush(val)
                self.assertTrue(my_heap.check())

        # large cases
        ub = 1000
        for _ in range(50):
            A = self.case(ub)
            N = self.case(ub)
            my_heap = minHeap(A)

            S = len(A)
            for val in N:
                my_heap.heappush(val)
                self.assertEqual(my_heap.size, S + 1)
                S += 1
            self.assertTrue(my_heap.check())

        # giant cases
        ub = 10000
        for _ in range(10):
            A = self.case(ub)
            N = self.case(ub)
            my_heap = minHeap(A)

            S = len(A)
            for val in N:
                my_heap.heappush(val)
                self.assertEqual(my_heap.size, S + 1)
                S += 1
            self.assertTrue(my_heap.check())
    
    def test_heappop(self):
        # small cases
        ub = 10
        for _ in range(500):
            A = self.case(ub)
            N = sorted(A, reverse=True)
            S = len(A)
            my_heap = minHeap(A)
            while not my_heap.isEmpty():
                self.assertEqual(my_heap.heappop(), N.pop())
                self.assertEqual(my_heap.size, S - 1)
                S -= 1
        
        # medium cases
        ub = 50
        for _ in range(100):
            A = self.case(ub)
            N = sorted(A, reverse=True)
            S = len(A)
            my_heap = minHeap(A)
            while not my_heap.isEmpty():
                self.assertEqual(my_heap.heappop(), N.pop())
                self.assertEqual(my_heap.size, S - 1)
                S -= 1
        
        # large cases
        ub = 1000
        for _ in range(50):
            A = self.case(ub)
            N = sorted(A, reverse=True)
            S = len(A)
            my_heap = minHeap(A)
            while not my_heap.isEmpty():
                self.assertEqual(my_heap.heappop(), N.pop())
                self.assertEqual(my_heap.size, S - 1)
                S -= 1


if __name__ == '__main__':
    unittest.main()