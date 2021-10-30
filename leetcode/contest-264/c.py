from collections import defaultdict
from typing import List


class Solution:
    def countHighestScoreNodes(self, parents: List[int]) -> int:
        def dfs1(u=0):
            sze[u] = 1
            for v in chd[u]:
                dfs1(v)
                sze[u] += sze[v]
        
        def dfs2(u=0):
            for v in chd[u]:
                dfs2(v)
                pnt[u] *= sze[v]
            if sze[0] - sze[u] > 0:
                pnt[u] *= sze[0] - sze[u]
        
        n = len(parents)
        sze = [0] * n
        pnt = [1] * n
        chd = defaultdict(list)
        for u, p in enumerate(parents):
            chd[p].append(u)
                
        dfs1()
        dfs2()
        return pnt.count(max(pnt))
 