from typing import List
from collections import Counter


class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        if len(changed) % 2 == 1:
            return []
        
        cnt = Counter(changed)
        
        ans = []
        for num in sorted(cnt.keys()):
            while cnt[num] > 0:
                cnt[num] -= 1
                ans.append(num)
                if cnt[2 * num] == 0:
                    return []
                cnt[2 * num] -= 1
        return ans