from sys import setrecursionlimit
from math import sqrt, ceil, factorial, gcd
from collections import defaultdict as ddt 
from collections import deque 
from bisect import bisect_left, bisect_right
from heapq import heapify, heappush, heappop, nlargest, nsmallest
from itertools import permutations, combinations, zip_longest

istr = lambda: input()
istrl = lambda: input().strip().split()
iint = lambda: int(input())
iintl = lambda: list(map(int, input().strip().split()))


def solve():
    return 0


if __name__ == "__main__":
    T = int(input())
    for t in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(t, ans))