from collections import Counter
from math import gcd
from typing import List


class Solution:
    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        mp = Counter()
        for w, h in rectangles:
            g = gcd(w, h)
            mp[w // g, h // g] += 1
        
        ans = 0
        for v in mp.values():
            ans += v * (v - 1) // 2
        return ans
