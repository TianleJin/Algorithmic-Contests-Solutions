class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        d = 0
        while True:
            if start - d >= 0 and nums[start - d] == target:
                return d
            if start + d < len(nums) and nums[start + d] == target:
                return d
            d += 1