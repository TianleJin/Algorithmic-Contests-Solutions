class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        ans = 0
        for c in costs:
            if c > coins:
                break
            coins -= c
            ans += 1
        return ans