from heapq import heappush, heappop
INF = float('inf')
class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        n = len(obstacles) - 1
        
        obs = set()
        for i, j in enumerate(obstacles):
            if j > 0:
                obs.add((i, j - 1))
        
        pq = []
        dist = [[INF] * 3 for _ in range(n + 1)]
        heappush(pq, (0, 0, 1))
        dist[0][1] = 0
        
        while pq:
            d, row, col = heappop(pq)
            if row == n: 
                return d
            
            if d > dist[row][col]:
                continue
            else:
                assert d == dist[row][col]
            
            nrow = row + 1
            if row < n and (nrow, col) not in obs and dist[row][col] < dist[nrow][col]:
                dist[nrow][col] = dist[row][col]
                heappush(pq, (dist[nrow][col], nrow, col))
                continue

            for ncol in (col - 1, col + 1, col - 2, col + 2):
                if ncol < 0 or ncol > 2 or (row, ncol) in obs or dist[row][col] + 1 >= dist[row][ncol]:
                    continue
                dist[row][ncol] = dist[row][col] + 1
                heappush(pq, (dist[row][ncol], row, ncol))
                
        return min(dist[n])