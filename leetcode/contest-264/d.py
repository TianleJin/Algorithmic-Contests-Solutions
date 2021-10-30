from collections import defaultdict, deque
from typing import List


class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        edges = defaultdict(list)
        deg = [0] * n
        ans = [0] * n
        for u, v in relations:
            u -= 1
            v -= 1
            edges[u].append(v)
            deg[v] += 1
        
        q = deque()
        for u in range(n):
            if deg[u] == 0:
                q.append(u)
                ans[u] = time[u]
        
        while q:
            u = q.popleft()
            for v in edges[u]:
                ans[v] = max(ans[v], ans[u] + time[v])
                deg[v] -= 1
                if deg[v] == 0:
                    q.append(v)
        return max(ans)