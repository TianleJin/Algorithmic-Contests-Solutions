from collections import defaultdict
from heapq import heappop, heappush
from typing import List


INF = float('inf')
class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
        E = defaultdict(list)
        for u, v in edges:
            u -= 1
            v -= 1
            E[u].append(v)
            E[v].append(u)
        
        dist = [[INF] * 2 for _ in range(n)]
        dist[0][0] = 0
        pq = [[0, 0]]
        while pq:
            t, u = heappop(pq)
            if t > dist[u][1]:
                continue
            
            nt = (t // change + 1) * change if (t // change) % 2 else t
            
            for v in E[u]:
                if nt + time < dist[v][0]:
                    dist[v][0] = nt + time
                    heappush(pq, [nt + time, v])
                elif dist[v][0] < nt + time < dist[v][1]:
                    dist[v][1] = nt + time
                    heappush(pq, [nt + time, v])
        return dist[n - 1][1]
