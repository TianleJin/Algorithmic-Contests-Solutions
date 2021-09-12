MOD = 10 ** 9 + 7

if __name__ == "__main__":
    T = int(input())
    for tt in range(1, T + 1):
        n, k = list(map(int, input().strip().split()))
        s = input().strip()

        power = [1] * n
        for i in range(n - 1):
            power[i + 1] = power[i] * k % MOD 

        ans = 0
        mid = (n + 1) // 2
        for i in range(mid):
            ans += (ord(s[i]) - ord('a')) * power[mid - i - 1]
            ans %= MOD
        
        t = s[:mid] + s[:mid-1][::-1] if n & 1 else s[:mid] + s[:mid][::-1]
        if t < s:
            ans += 1
            ans %= MOD
        print("Case #{}: {}".format(tt, ans))