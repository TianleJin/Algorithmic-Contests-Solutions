from collections import deque, defaultdict
from heapq import heapify, heappop, heappush
it = lambda: list(map(int, input().strip().split()))

def solve():
    l, r, m = it()
    for a in range(l, r + 1):
        u1 = m % a
        v1 = m // a
        if v1 != 0 and l + u1 <= r:
            print(a, l + u1, l)
            return
        v2 = (m // a + 1) * a
        u2 = v2 - m
        if l + u2 <= r:
            print(a, l, l + u2)
            return

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solve()