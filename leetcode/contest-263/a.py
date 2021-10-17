class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        nums = [int(x) for x in s.split() if any(ch in x for ch in "0123456789")]
        for i in range(len(nums) - 1):
            if nums[i] >= nums[i + 1]:
                return False
        return True
