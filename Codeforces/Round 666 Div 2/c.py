from math import ceil
from collections import deque, defaultdict
from heapq import heapify, heappop, heappush
INF = float('inf')
it = lambda: list(map(int, input().strip().split()))


def output(l, r, v):
    print(l, r)
    print(" ".join(map(str, v)))


def solve():
    n = int(input())
    A = it()
    if n == 1:
        output(1, 1, [-A[0]])
        output(1, 1, [0])
        output(1, 1, [0])
    else:
        output(1, 1, [(n - 1) * A[0]])
        output(2, n, [(n - 1) * A[i] for i in range(1, n)])
        output(1, n, [-n * A[i] for i in range(n)])


if __name__ == '__main__':
    # T = int(input())
    # for _ in range(T):
    solve()