MXA = 2000000
class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        def good(num):
            cnt = [0] * 10
            while num > 0:
                cnt[num % 10] += 1
                num //= 10
            
            for i in range(10):
                if cnt[i] > 0 and cnt[i] != i:
                    return False
            return True
                
        for num in range(n + 1, MXA):
            if good(num):
                return num
        return 1224444