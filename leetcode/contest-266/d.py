from collections import Counter, defaultdict
from typing import List


class Solution:
    def maximalPathQuality(self, values: List[int], edges: List[List[int]], maxTime: int) -> int:
        n = len(values)
        E = defaultdict(list)
        for u, v, t in edges:
            E[u].append((v, t))
            E[v].append((u, t))
        
        self.ans = 0
        edge_vis = set()
        node_vis = Counter()
        
        def dfs(u, time, total):
            node_vis[u] += 1
            if node_vis[u] == 1:
                total += values[u]
            
            if u == 0:
                self.ans = max(self.ans, total)
            
            for v, t in E[u]:
                if (u, v) not in edge_vis and t <= time:
                    edge_vis.add((u, v))
                    dfs(v, time - t, total)
                    edge_vis.discard((u, v))
            node_vis[u] -= 1
        
        dfs(0, maxTime, 0)
        return self.ans
