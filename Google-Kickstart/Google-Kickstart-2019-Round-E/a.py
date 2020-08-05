from collections import defaultdict
it = lambda: list(map(int, input().strip().split()))


def find(par, u):
    if par[u] != u:
        par[u] = find(par, par[u])
    return par[u]


def union(par, rnk, x, y):
    if x == y:
        return
    elif rnk[x] > rnk[y]:
        par[y] = x
    elif rnk[x] < rnk[y]:
        par[x] = y
    else:
        par[x] = y
        rnk[y] += 1


def solve():
    N, M = it()

    par = [0] * N
    rnk = [0] * N
    for i in range(N):
        par[i] = i

    for _ in range(M):
        u, v = it()
        u -= 1
        v -= 1
        union(par, rnk, find(par, u), find(par, v))

    groups = defaultdict(int)
    for u in range(N):
        x = find(par, u)
        groups[x] += 1
    
    ans = (len(groups) - 1) << 1
    for c in groups.values():
        ans += c - 1
    return ans


if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))