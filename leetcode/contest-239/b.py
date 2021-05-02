class Solution:
    def splitString(self, s: str) -> bool:
        def dfs(i, curr=[], last=-1):
            if i == len(s):
                if not curr: return True
                res = int(''.join(curr))
                return res + 1 == last
            
            if dfs(i + 1, curr + [ s[i] ], last):
                return True
            
            if curr:
                res = int(''.join(curr))
                if last in (-1, res + 1) and dfs(i + 1, [ s[i] ], res):
                    return True
            return False
        return dfs(0)
            