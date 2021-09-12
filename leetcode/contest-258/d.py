from typing import List


class Solution:
    def smallestMissingValueSubtree(self, parents: List[int], nums: List[int]) -> List[int]:
        class SegmentTree:
            def __init__(self, size):
                self.size = size
                self.tree = [0] * (2 * size)
            
            def update(self, idx, val):
                idx += self.size
                self.tree[idx] = max(self.tree[idx], val)
                while idx > 1:
                    idx >>= 1
                    self.tree[idx] = max(self.tree[2 * idx], self.tree[2 * idx + 1])
            
            def query(self, l, r):
                l += self.size
                r += self.size
                ret = 0
                while l < r:
                    if l & 1:
                        ret = max(ret, self.tree[l])
                        l += 1
                    if r & 1:
                        r -= 1
                        ret = max(ret, self.tree[r])
                    l >>= 1
                    r >>= 1
                return ret
                
        class LCA:
            def __init__(self, parents):
                self.T = 0
                self.L = 20
                self.N = len(parents)
                self.root = parents.index(-1)
                self.start = [0] * self.N
                self.end = [0] * self.N
                
                self.dp = [[-1] * N for _ in range(self.L)]
                self.children = [[] for _ in range(self.N)]
                for u, p in enumerate(parents):
                    self.dp[0][u] = p
                    if p != -1:
                        self.children[p].append(u)
                    
                self.tour(self.root)
                self.jump()
            
            def tour(self, u):
                self.start[u] = self.T
                self.T += 1
                for v in self.children[u]:
                    self.tour(v)
                self.end[u] = self.T - 1
            
            def jump(self):
                for i in range(1, self.L):
                    for u in range(self.N):
                        if self.dp[i - 1][u] != -1:
                            self.dp[i][u] = self.dp[i - 1][self.dp[i - 1][u]]
            
            def isAncestor(self, u, v):
                if u == -1: return True
                return self.start[u] <= self.start[v] and self.end[v] <= self.end[u]
            
            def getStart(self, u):
                return self.start[u]
            
            def getEnd(self, u):
                return self.end[u]
            
            def getLCA(self, u, v):
                if self.isAncestor(u, v): return u
                if self.isAncestor(v, u): return v
                
                p = u
                for i in range(self.L - 1, -1, -1):
                    if not self.isAncestor(self.dp[i][p], v):
                        p = self.dp[i][p]
                return self.dp[0][p]
        
        N = len(parents)
        mp = {num: u for u, num in enumerate(nums)}
        lca = LCA(parents)
        seg = SegmentTree(lca.T)
        
        cur = None
        for num in range(1, max(nums) + 1):
            if num not in mp: break
            cur = mp[num] if cur is None else lca.getLCA(cur, mp[num])
            seg.update(lca.getStart(cur), num)
        
        answer = [0] * N
        for u in range(N):
            answer[u] = seg.query(lca.getStart(u), lca.getEnd(u) + 1) + 1
        return answer
