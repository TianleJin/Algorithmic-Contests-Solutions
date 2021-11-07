from collections import deque
from typing import List


INF = float('inf')
class Solution:
    def minimumOperations(self, nums: List[int], start: int, goal: int) -> int:
        n = len(nums)
        dp = [INF] * 1001
        dp[start] = 0
        q = deque([start])
        while q:
            x = q.popleft()
            for num in nums:
                for nx in [x + num, x - num, x ^ num]:
                    if nx == goal:
                        return dp[x] + 1
                    if 0 <= nx <= 1000 and dp[nx] == INF:
                        dp[nx] = dp[x] + 1
                        q.append(nx)
        return -1