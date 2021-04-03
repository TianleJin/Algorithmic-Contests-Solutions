from math import ceil
from collections import deque, defaultdict
from heapq import heapify, heappop, heappush
INF = float('inf')
it = lambda: list(map(int, input().strip().split()))


def solve():
    input()
    A = it()
    S = sum(A)
    M = max(A)
    print("T" if M > S - M or S % 2 == 1 else "HL")


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solve()