from sys import setrecursionlimit
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
    return 0

if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))