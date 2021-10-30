class Manacher:
    def __init__(self, s):
        self.s = s
    
    def build(self):
        self.build_odd()
        self.build_even()

    def build_odd(self):
        s = self.s
        n = len(s)
        l = 0
        r = -1
        rad = [0] * n
        for i in range(n):
            k = 1 if i > r else min(rad[l + r - i], r - i + 1)
            while i - k >= 0 and i + k < n and s[i - k] == s[i + k]:
                k += 1
            rad[i] = k
            k -= 1
            if i + k > r:
                l = i - k
                r = i + k
        self.odd = rad
    
    def build_even(self):
        s = self.s
        n = len(s)
        l = 0
        r = -1
        rad = [0] * n
        for i in range(n):
            k = 0 if i > r else min(rad[l + r - i + 1], r - i + 1)
            while i - k - 1 >= 0 and i + k < n and s[i - k - 1] == s[i + k]:
                k += 1
            rad[i] = k
            k -= 1
            if i + k > r:
                l = i - k - 1
                r = i + k
        self.even = rad

    def getLongest(self):
        sze = 0
        idx = 0
        for i, l in enumerate(self.odd):
            if 2 * l - 1 > sze:
                sze = 2 * l - 1
                idx = i - l + 1
        
        for i, l in enumerate(self.even):
            if 2 * l > sze:
                sze = 2 * l
                idx = i - l
        return self.s[idx:idx + sze]


if __name__ == "__main__":
    s = input().strip()
    solver = Manacher(s)
    solver.build()
    print(solver.getLongest())