class Solution:
    def longestBeautifulSubstring(self, word: str) -> int:
        ans = 0
        cur = 1
        vis = { word[0], }
        for i in range(1, len(word)):
            if word[i] >= word[i - 1]:
                cur += 1
            else:
                vis = set()
                cur = 1
            vis.add(word[i])
            if len(vis) == 5:
                ans = max(ans, cur)
        return ans