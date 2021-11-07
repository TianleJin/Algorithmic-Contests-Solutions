import string
from functools import lru_cache


class Solution:
    def possiblyEquals(self, s1: str, s2: str) -> bool:
        char = set(string.ascii_lowercase)
        @lru_cache(None)
        def dp(i=0, j=0, e=0):
            if i == len(s1) and j == len(s2):
                return e == 0
            
            if i < len(s1) and s1[i] not in char:
                k = i
                while k < len(s1) and s1[k] not in char:
                    if dp(k + 1, j, e + int(s1[i:k + 1])):
                        return True
                    k += 1
                return False
            
            if j < len(s2) and s2[j] not in char:
                k = j
                while k < len(s2) and s2[k] not in char:
                    if dp(i, k + 1, e - int(s2[j:k + 1])):
                        return True
                    k += 1
                return False
            
            if e > 0:
                return j < len(s2) and dp(i, j + 1, e - 1)
            elif e < 0:
                return i < len(s1) and dp(i + 1, j, e + 1)
            else:
                return i < len(s1) and j < len(s2) and s1[i] == s2[j] and dp(i + 1, j + 1, e)
        return dp()
