from typing import List


class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        mxx = 0
        for ride in rides:
            mxx = max(mxx, ride[1])
            
        rides.sort()
        
        dp = [0] * (mxx + 1)
        
        j = 0
        for i in range(1, mxx + 1):
            while j < len(rides) and rides[j][0] == i:
                s, e, t = rides[j]
                dp[e] = max(dp[e], dp[i] + e - s + t)
                j += 1
            if i < mxx:
                dp[i + 1] = max(dp[i + 1], dp[i])
        return dp[mxx]