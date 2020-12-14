from math import sqrt, log2, ceil, floor, sin, cos, tan, pi
from collections import defaultdict, deque, Counter
from heapq import heapify, heappush, heappop, heappushpop
from functools import lru_cache
from itertools import permutations, combinations, product
from random import random, randint, choice, sample
from bisect import bisect_left, bisect_right, insort
it = lambda: list(map(int, input().strip().split()))
INF = float('inf')


def case():
    pass


def brute():
    pass


def solve():
    N = int(input())
    A = it()

    ans = 0
    mx = -INF
    for i in range(N):
        if A[i] > mx and (i + 1 == N or A[i] > A[i + 1]):
            ans += 1
        mx = max(mx, A[i])
    return ans


if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))