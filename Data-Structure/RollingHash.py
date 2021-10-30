class RollingHash:
    def __init__(self, s, p=31, q=1000000007):
        self.n = len(s)
        self.s = s
        self.p = p
        self.q = q

    def build(self):
        self.build_prefix()
        self.build_inverse()
    
    def build_prefix(self):
        arr = [ord(ch) - ord('a') for ch in self.s]
        pre = [0] * self.n
        pre[0] = arr[0]

        x = 1
        for i in range(1, self.n):
            x = x * self.p % self.q
            pre[i] = (pre[i - 1] + arr[i] * x) % self.q
        self.pre = pre
    
    def build_inverse(self):
        x = pow(self.p, self.q - 2, self.q)
        inv = [1] * self.n
        for i in range(1, self.n):
            inv[i] = inv[i - 1] * x % self.q
        self.inv = inv

    def query(self, l, r):
        res = self.pre[r]
        if l > 0:
            res = (res - self.pre[l - 1]) % self.q
        return res * self.inv[l] % self.q
    
    def search(self, pattern):
        if len(pattern) > self.n:
            return []

        m = len(pattern)
        
        arr = [ord(ch) - ord('a') for ch in pattern]
        h = 0
        x = 1
        for i in range(m):
            h = (h + x * arr[i]) % self.q
            x = x * self.p % self.q

        res = []
        for i in range(self.n - m + 1):
            if h == self.query(i, i + m - 1):
                res.append(i)
        return res


if __name__ == "__main__":
    def test():
        strings = [
            "ababbaab",
            "abbbabba",
            "ababbabbbabababab",
            "ababbaab",
            "a" * 100000,
            "a" * 100000,
        ]
        patterns = [
            "ab",
            "bbb",
            "bab",
            "baba",
            "a",
            "a" * 10000
        ]
        answers = [
            [0, 2, 6],
            [1],
            [1, 4, 8, 10, 12, 14],
            [], 
            list(range(100000)), 
            list(range(90001))
        ]

        for s, pattern, answer in zip(strings, patterns, answers):
            rolling_hash = RollingHash(s)
            rolling_hash.build()
            assert rolling_hash.search(pattern) == answer, len(rolling_hash.search(pattern))
    
    test()