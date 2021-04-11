from collections import defaultdict
class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        ans = [0] * k
        cnt = defaultdict(int)
        vis = defaultdict(set)
        for i, t in logs:
            if not t in vis[i]:
                cnt[i] += 1
                vis[i].add(t)
        
        for i in cnt:
            ans[cnt[i] - 1] += 1
        return ans