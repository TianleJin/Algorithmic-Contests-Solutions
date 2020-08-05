from random import randint
from math import log2
from collections import defaultdict
it = lambda: list(map(int, input().strip().split()))
INF = float('inf')


def build(segtree, N, n):
    for i in range(N - 1, 0, -1):
        if n % 2 == int(log2(i)) % 2:
            segtree[i] = segtree[i << 1] ^ segtree[i << 1 | 1]
        else:
            segtree[i] = segtree[i << 1] | segtree[i << 1 | 1]


def update(segtree, N, n, i, val):
    i += N
    segtree[i] = val
    while i > 1:
        i >>= 1
        if n % 2 == int(log2(i)) % 2:
            segtree[i] = segtree[i << 1] ^ segtree[i << 1 | 1]
        else:
            segtree[i] = segtree[i << 1] | segtree[i << 1 | 1]


def query(segtree):
    return segtree[1]


def solve():
    n, m = it()
    A = it()
    N = 1 << n

    segtree = [0] * (N << 1)
    for i in range(N):
        segtree[i + N] = A[i]
    build(segtree, N, n)

    ans = []
    for _ in range(m):
        i, val = it()
        update(segtree, N, n, i - 1, val)
        ans.append(query(segtree))
    
    for v in ans:
        print(v)

    
if __name__ == '__main__':
    solve()