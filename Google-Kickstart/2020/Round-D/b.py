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
    K = int(input())
    A = it()

    dp = [[INF] * 4 for _ in range(K)]
    for j in range(4):
        dp[0][j] = 0
    
    for i in range(1, K):
        for j in range(4):
            for k in range(4):
                if A[i] == A[i - 1]:
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + int(j != k))
                elif A[i] > A[i - 1]:
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + int(j <= k))
                else:
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + int(j >= k))
    return min(dp[K - 1])


if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))