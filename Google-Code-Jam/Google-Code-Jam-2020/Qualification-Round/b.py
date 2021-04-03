def solve(s, t):
    def dfs(s, l):
        if all(int(ch) < l for ch in s):
            return list(s)
        ans = []
        end = 0
        while end < len(s):
            tmp = ""
            while end < len(s) and int(s[end]) >= l:
                tmp += s[end]
                end += 1
            if not tmp:
                ans.append(s[end])
                end += 1
            else:
                ans.append('(')
                ans.extend(dfs(tmp, l + 1))
                ans.append(')')
        return ans
    
    print("Case #{}: {}".format(t, ''.join(dfs(s, 1))))


if __name__ == "__main__":
    T = int(input())
    for t in range(1, T + 1):
        solve(input().strip(), t)