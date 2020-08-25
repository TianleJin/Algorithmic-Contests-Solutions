from collections import defaultdict
from heapq import heappush, heappop
it = lambda: list(map(int, input().strip().split()))
INF = 1e12


def solve():
    # N: number of junctions
    # M: number of streets
    # S: number of stones
    # R: number of recipes
    N, M, S, R = it()

    # making graph
    edges = defaultdict(list)
    for _ in range(M):
        u, v = it()
        u -= 1
        v -= 1
        edges[u].append(v)
        edges[v].append(u)
    
    # get stones for each junction
    stones = defaultdict(list)
    for i in range(N):
        for s in it()[1:]:
            stones[i].append(s - 1)

    # get recipes for each junction
    products = [0] * R
    num_inputs = [0] * R
    users = defaultdict(list)
    for i in range(R):
        recipe = it()
        num_inputs[i] = recipe[0]
        products[i] = recipe[-1] - 1
        for p in recipe[1:-1]:
            p -= 1
            users[p].append(i)

    stone_dist = defaultdict(lambda: INF)
    recipe_dist = defaultdict(lambda: [0, 0])
    
    pq = []
    for i in range(N):
        for s in stones[i]:
            stone_dist[s, i] = 0
            heappush(pq, (0, s, i))
    
    # dijkstra
    while pq:
        d, s, cur = heappop(pq)
        assert d >= stone_dist[s, cur]
        if d != stone_dist[s, cur]: continue
        for r in users[s]:
            recipe_dist[r, cur][0] += 1
            recipe_dist[r, cur][1] += d 
            if recipe_dist[r, cur][0] == num_inputs[r]:
                nd = recipe_dist[r, cur][1]
                p = products[r]
                if nd < stone_dist[p, cur]:
                    stone_dist[p, cur] = nd
                    heappush(pq, (nd, p, cur))
        for adj in edges[cur]:
            nd = d + 1
            if nd < stone_dist[s, adj]:
                stone_dist[s, adj] = nd
                heappush(pq, (nd, s, adj))
    
    ans = INF
    for i in range(N):
        ans = min(ans, stone_dist[0, i])
    return -1 if ans == INF else ans
    

if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))