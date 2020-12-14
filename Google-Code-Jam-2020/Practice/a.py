from sys import setrecursionlimit
from collections import defaultdict
INF = float('inf')
it = lambda: list(map(int, input().strip().split()))
setrecursionlimit(100100)


def solve():
    # summit point at 1
    N = int(input())
    edge_list = defaultdict(list)
    for _ in range(N - 1):
        u, v, s, c = it()
        edge_list[u].append((v, s, c))
    
    def dfs(u, need, last):
        ret = defaultdict(int)
        for v, s, c in edge_list[u]:
            res = dfs(v, min(need, s), c)
            for val, cnt in res.items():
                if val < 0 and val + last < 0:
                    ret[val + last] += cnt
        tot = 0
        ans = defaultdict(int)
        for val, cnt in sorted(ret.items()):
            assert val < 0
            if tot + cnt >= need:
                ans[val] += need - tot
                tot = need
                break
            else:
                ans[val] += cnt
                tot += cnt
        if tot < need and last < 0:
            ans[last] += need - tot
        return ans

    cnt = 0
    cst = 0
    for u, s, c in edge_list[1]:
        tot = 0
        cnt += s
        cst += s * c
        res = dfs(u, s, 0)
        for v, f in sorted(res.items()):
            assert v < 0
            if tot + f >= s:
                cst += v * (s - tot)
                tot = s
                break
            else:
                cst += v * f
                tot += f
    return cnt, cst
        

if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {} {}'.format(tt, *ans))