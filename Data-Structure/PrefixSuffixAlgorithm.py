class PrefixSuffixAlgorithm:
    @staticmethod
    def zs(s):
        n = len(s)
        z = [0] * n
        l = r = 0
        for i in range(1, n):
            if r < i:
                l = r = i
                while r < n and s[r] == s[r - l]:
                    r += 1
                z[i] = r - l
                r -= 1
            else:
                k = i - l
                if z[k] < r - i + 1:
                    z[i] = z[k]
                else:
                    l = i
                    while r < n and s[r] == s[r - l]:
                        r += 1
                    z[i] = r - l
                    r -= 1
        return z
    
    @staticmethod
    def kmp(s):
        n = len(s)
        theta = [0] * n
        l = 0
        for i in range(1, n):
            while l > 0 and s[i] != s[l]:
                l = theta[l - 1]
            if s[i] == s[l]:
                l += 1
            theta[i] = l
        return theta


if __name__ == "__main__":
    s = input().strip()
    z = PrefixSuffixAlgorithm.zs(s)
    theta = PrefixSuffixAlgorithm.kmp(s)
    print(" ".join(map(str, z)))
    print(" ".join(map(str, theta)))
