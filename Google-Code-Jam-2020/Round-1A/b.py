from sys import setrecursionlimit
from math import sqrt, ceil, factorial, gcd
from collections import defaultdict as ddt 
from collections import deque 
from bisect import bisect_left, bisect_right
from heapq import heapify, heappush, heappop, nlargest, nsmallest
from itertools import permutations, combinations, zip_longest

istr = lambda: input().strip()
istrl = lambda: input().strip().split()
iint = lambda: int(input())
iintl = lambda: list(map(int, input().strip().split()))


def solve(N):
    rows = min(30, N)
    N -= rows
    use = [0] * rows
    for row in range(rows - 1, -1, -1):
        if (N >= (1 << row) - 1):
            use[row] = 1
            N -= (1 << row) - 1
    rows += N
    use += [0] * N

    side = 0
    for row in range(rows):
        if use[row]:
            if side == 1:
                for col in range(row + 1):
                    print(row + 1, col + 1)
            else:
                for col in range(row, -1, -1):
                    print(row + 1, col + 1)
            side ^= 1
        else:
            if side == 1:
                print(row + 1, 1)
            else:
                print(row + 1, row + 1)


if __name__ == "__main__":
    T = int(input())
    for t in range(1, T + 1):
        print("Case #{}:".format(t))
        solve(iint())
        