from typing import List


class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        ans = 0
        cnt = 0
        for i in range(1 << len(nums)):
            tot = 0
            for j in range(len(nums)):
                if i >> j & 1:
                    tot |= nums[j]
            if tot > ans:
                ans = tot
                cnt = 1
            elif tot == ans:
                cnt += 1
        return cnt
