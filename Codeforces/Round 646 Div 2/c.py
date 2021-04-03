from functools import lru_cache
MOD = 998244353


def solve():
    S = input().strip()
    T = input().strip()
    N = len(S)
    M = len(T)

    dp = [[0] * N for _ in range(N)]
    
    for j in range(N):
        if j >= M or S[0] == T[j]:
            dp[j][j] = 2
    
    for i in range(2, N + 1):
        for j in range(N - i + 1):
            k = j + i - 1
            if j >= M or S[i - 1] == T[j]:
                dp[j][k] = (dp[j][k] + dp[j + 1][k]) % MOD
            if j + i - 1 >= M or S[i - 1] == T[k]:
                dp[j][k] = (dp[j][k] + dp[j][k - 1]) % MOD
    ans = 0
    for i in range(M - 1, N):
        ans = (ans + dp[0][i]) % MOD
    return ans


if __name__ == '__main__':
    print(solve())