from math import gcd
from collections import defaultdict
class Solution:
    def countDifferentSubsequenceGCDs(self, nums: List[int]) -> int:
        ans = 0
        mxn = max(nums)
        can = defaultdict(bool)
        for num in nums:
            if not can[num]:
                can[num] = True
                ans += 1
        
        num = mxn
        while num > 0:
            if can[num]: 
                num -= 1
                continue
            
            g = 0
            x = num
            while x <= mxn:
                if can[x]:
                    g = gcd(g, x)
                    if g == num:
                        break
                x += num
                
            if g == num:
                can[num] = True
                ans += 1
            num -= 1
        return ans