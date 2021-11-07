class Solution:
    def countVowels(self, word: str) -> int:
        vowels = set("aeiou")
        ans = 0
        for i in range(len(word)):
            if word[i] in vowels:
                ans += (i + 1) * (len(word) - i)
        return ans
