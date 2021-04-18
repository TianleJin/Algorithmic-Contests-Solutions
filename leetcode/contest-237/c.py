from heapq import heappush, heappop
class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        n = len(tasks)
        ind = list(range(n))
        ind.sort(key=lambda i:tasks[i])
        
        i = 0
        t = 0
        ans = [-1] * n
        
        pq = []
        for j in range(n):
            while i < n and (not pq or t >= tasks[ind[i]][0]):
                t = max(t, tasks[ind[i]][0])
                heappush(pq, (tasks[ind[i]][1], ind[i]))
                i += 1
            dt, idx = heappop(pq)
            ans[j] = idx
            t += dt
        return ans