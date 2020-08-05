from collections import defaultdict
it = lambda: list(map(int, input().strip().split()))
INF = float('inf')


def find(par, u):
    if par[u] != u:
        par[u] = find(par, par[u])
    return par[u]


def union(rnk, par, u, v):
    x, y = find(par, u), find(par, v)
    if rnk[x] > rnk[y]:
        par[y] = x
    elif rnk[x] < rnk[y]:
        par[x] = y
    else:
        par[x] = y
        rnk[y] += 1


def solve():
    N = int(input())
    E = defaultdict(list)
    for _ in range(N - 1):
        u, v = it()
        x, y = min(u, v), max(u, v)
        E[x].append(y)
    
    for u in range(1, N + 1):
        E[u].sort()

    par = [0] * (N + 1)
    rnk = [0] * (N + 1)
    for u in range(1, N + 1):
        par[u] = u

    ans = 0
    cur = 0
    for u in range(N, 0, -1):
        if E[u]:
            v = E[u][0]
            cur += v - u
            union(rnk, par, u, v)
        else:
            cur += N + 1 - u
        for v in E[u][1:]:
            if find(par, v) != find(par, u):
                cur -= (N + 1 - v)
                union(rnk, par, u, v)
        ans += cur
    return ans


if __name__ == '__main__':
    print(solve())