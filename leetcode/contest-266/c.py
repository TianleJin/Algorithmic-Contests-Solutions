from typing import List


class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        def possible(k):
            cnt = 0
            for q in quantities:
                cnt += (q + k - 1) // k
            return cnt <= n
        
        lo = 1
        hi = max(quantities)
        while lo < hi:
            mid = (lo + hi) // 2
            if possible(mid):
                hi = mid
            else:
                lo = mid + 1
        return lo
