class Solution:
    def maxProduct(self, s: str) -> int:
        n = len(s)
        dp = [0] * (1 << n)
        for i in range(1, 1 << n):
            for l in range(n):
                if i >> l & 1: break
                    
            for r in range(n - 1, -1, -1):
                if i >> r & 1: break
            
            if l == r:
                dp[i] = 1
            elif s[l] == s[r]:
                dp[i] = dp[i ^ 1 << l ^ 1 << r] + 2
            else:
                dp[i] = max(dp[i ^ 1 << r], dp[i ^ 1 << l])
        
        ans = 0
        for i in range(1, 1 << n):
            ans = max(ans, dp[i] * dp[i ^ (1 << n) - 1])
        return ans
