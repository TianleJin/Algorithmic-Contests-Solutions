from collections import deque, defaultdict
from heapq import heapify, heappop, heappush
it = lambda: list(map(int, input().strip().split()))


def solve():
    n, m = it()
    F = [it() for _ in range(m)]
    F.sort(reverse=True)

    prefix = [0] * m
    prefix[0] = F[0][0]
    for i in range(1, m):
        prefix[i] = prefix[i - 1] + F[i][0]
    
    ans = 0
    for i in range(m):
        a, b = F[i]
        if b >= F[0][0]:
            ans = max(ans, a + (n - 1) * b)
            continue

        lo = 0
        hi = m - 1
        while lo < hi:
            mi = (lo + hi + 1) >> 1
            if F[mi][0] >= b:
                lo = mi
            else:
                hi = mi - 1

        if lo + 1 >= n:
            ans = max(ans, prefix[min(lo, n - 1)])
        elif a >= b:
            ans = max(ans, prefix[lo] + (n - lo - 1) * b)
        else:
            ans = max(ans, prefix[lo] + a + (n - lo - 2) * b)
    print(ans)


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        solve()
        if i + 1 < T:
            input()