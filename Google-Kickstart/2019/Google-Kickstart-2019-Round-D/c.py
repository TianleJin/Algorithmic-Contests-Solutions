from random import randint, random
from collections import defaultdict
from heapq import heappush, heappop
it = lambda: list(map(int, input().strip().split()))
INF = float('inf')


def solve():
    K, N = it() 
    dist = it()
    cost = it()
    
    A = [[d, c] for d, c in zip(dist, cost)]
    A.sort()
    
    dist, cost = zip(*A)
    llim = K >> 1
    rlim = K - llim

    cur = 0
    pq1 = []
    dp1 = [INF] * N
    for i in range(N - 1, -1, -1):
        cur += dist[i] + cost[i]
        heappush(pq1, -dist[i] - cost[i])
        while len(pq1) > llim:
            cur += heappop(pq1)
        if len(pq1) == llim:
            dp1[i] = min(dp1[i + 1] if i + 1 < N else INF, cur)

    cur = 0
    pq2 = []
    dp2 = [INF] * N
    for i in range(N):
        cur += cost[i] - dist[i]
        heappush(pq2, dist[i] - cost[i])
        while len(pq2) > rlim:
            cur += heappop(pq2)
        if len(pq2) == rlim:
            dp2[i] = min(dp2[i - 1] if i > 0 else INF, cur)
    
    ans = INF
    for i in range(N):
        r_cost = dp1[i + 1] if i + 1 < N else 0 if llim == 0 else INF
        l_cost = dp2[i - 1] if i > 0 else 0 if rlim == 0 else INF
        ans = min(ans, r_cost + l_cost + (rlim - llim) * dist[i] + cost[i])
    return ans


if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))