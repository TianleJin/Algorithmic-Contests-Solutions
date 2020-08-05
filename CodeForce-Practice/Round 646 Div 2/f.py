INF = float('inf')


def solve():
    N = int(input())
    A = input().strip()
    B = input().strip()

    Acount = [[0] * 26 for _ in range(N + 1)]
    Bcount = [[0] * 26 for _ in range(N + 1)]
    for i in range(N - 1, -1, -1):
        Acount[i][ord(A[i]) - ord('a')] += 1
        Bcount[i][ord(B[i]) - ord('a')] += 1
        for j in range(26):
            Acount[i][j] += Acount[i + 1][j]
            Bcount[i][j] += Bcount[i + 1][j]

    for i in range(26):
        if Acount[0][i] != Bcount[0][i]:
            return -1

    dp = [[INF] * (N + 1) for _ in range(N + 1)]
    for j in range(N + 1):
        dp[0][j] = 0
    
    for i in range(1, N + 1):
        s = ord(A[i - 1]) - ord('a')
        for j in range(i, N + 1):
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1)

            t = ord(B[j - 1]) - ord('a')
            if Acount[i][t] > Bcount[j][t]:
                dp[i][j] = min(dp[i][j], dp[i][j - 1])
            if s == t:
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1])

    # for row in dp:
    #     print(row)

    return dp[N][N]


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        print(solve())