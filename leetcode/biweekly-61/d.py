from typing import List


class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        nums = sorted(set(nums))
        ans = n - 1
        cnt = 1
        gap = 0
        l = 0
        for r in range(1, len(nums)):
            cnt += 1
            gap += nums[r] - nums[r - 1] - 1
            while cnt + gap > n:
                gap -= nums[l + 1] - nums[l] - 1
                cnt -= 1
                l += 1
            ans = min(ans, n - cnt)
        return ans