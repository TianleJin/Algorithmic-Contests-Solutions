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
    print(1)
    print(10 ** 5, 100, 200)
    print(' '.join(map(str, list(range(1, 10 ** 5)))))


def solve():
    N, A, B = it()
    par = it()
    chd = defaultdict(list)
    for i in range(N - 1):
        chd[par[i]].append(i + 2)
    
    I = defaultdict(int)
    Pa = [0] * (N + 1)
    Pb = [0] * (N + 1)
    stack = []

    curr = 1
    while True:
        if I[curr] < len(chd[curr]):
            stack.append(curr)
            temp = chd[curr][I[curr]]
            I[curr] += 1
            curr = temp
        else:
            Pa[curr] += 1
            Pb[curr] += 1
            if len(stack) >= A:
                Pa[stack[-A]] += Pa[curr]
            if len(stack) >= B:
                Pb[stack[-B]] += Pb[curr]
            if not stack:
                break
            else:
                curr = stack.pop()

    ans = 0
    for a, b in zip(Pa, Pb):
        x = a / N
        y = b / N
        ans += x + y - x * y
    return ans


if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))
    # case()