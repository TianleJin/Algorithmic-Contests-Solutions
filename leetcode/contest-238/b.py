class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()
        
        pref = [0] * (n + 1)
        for i in range(n):
            pref[i + 1] = pref[i] + nums[i]
        
        ans = 0
        for i in range(n):
            lo = 0
            hi = i
            while lo < hi:
                mi = lo + hi >> 1
                total = pref[i + 1] - pref[mi]
                count = i - mi + 1
                if count * nums[i] - total <= k:
                    hi = mi
                else:
                    lo = mi + 1
            ans = max(ans, i - lo + 1)
        return ans