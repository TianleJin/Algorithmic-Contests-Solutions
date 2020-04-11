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
    print(1, 1)
    if N == 1:
        return

    print(2, 1)
    if N == 2:
        return 

    if N == 3:
        print(2, 2)
        return

    N -= 2
    j = 3
    val = 2

    while N >= val:
        print(j, 2)
        N -= val
        val += 1
        j += 1
    
    j -= 1
    while N > 0:
        print(j, 1)
        N -= 1
        j += 1


if __name__ == "__main__":
    T = int(input())
    for t in range(1, T + 1):
        print("Case #{}:".format(t))
        solve(iint())
        