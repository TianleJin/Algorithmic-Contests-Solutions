from bisect import bisect_left
mod = 10 ** 9 + 7
inf = float('inf')
class Solution:
    def minAbsoluteSumDiff(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        nums = sorted(nums1)
        
        tot = 0
        for a, b in zip(nums1, nums2):
            tot += abs(a - b)
            
        ans = inf
        for x, y in zip(nums1, nums2):
            idx = bisect_left(nums, y)
            if idx < n:
                ans = min(ans, tot + abs(y - nums[idx]) - abs(x - y))
            if idx > 0:
                idx -= 1
                ans = min(ans, tot + abs(y - nums[idx]) - abs(x - y))
        return ans % mod