PUNC = (',', '.', '!')
class Solution:
    def countValidWords(self, sentence: str) -> int:
        def check_hyphen(word):
            hyphen = word.count('-')
            if hyphen == 0:
                return True
            
            idx = word.index('-')
            return hyphen == 1 and 0 < idx < len(word) - 1 and word[idx - 1].isalpha() and word[idx + 1].isalpha()
        
        def check_digit(word):
            return all(not ch.isdigit() for ch in word)
        
        def check_punc(word):
            cnt = sum(word.count(ch) for ch in PUNC)
            return cnt == 0 or cnt == 1 and word[-1] in PUNC
                
        ans = 0
        for word in sentence.split():
            if check_digit(word) and check_hyphen(word) and check_punc(word):
                ans += 1
        return ans
