class Solution:
    def getXORSum(self, arr1: List[int], arr2: List[int]) -> int:
        ans = 0
        for i in range(30):
            if sum(x >> i & 1 for x in arr1) * sum(x >> i & 1 for x in arr2) & 1:
                ans ^= 1 << i
        return ans