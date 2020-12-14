it = lambda: list(map(int, input().strip().split()))
INF = float('inf')


def solve():
    R, C, K = it()
    grid = [[0] * C for _ in range(R)]
    for _ in range(K):
        r, c, v = it()
        grid[r - 1][c - 1] = v
    
    dp = [[[-INF] * 4 for _ in range(C + 1)] for _ in range(R + 1)]

    for i in range(R + 1):
        dp[i][0][0] = 0
    
    for j in range(C + 1):
        dp[0][j][0] = 0
    
    for i in range(1, R + 1):
        for j in range(1, C + 1):
            for k in range(4):
                dp[i][j][k] = dp[i][j - 1][k]
            for k in range(4):
                dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][k])
                if grid[i - 1][j - 1] > 0:
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][k] + grid[i - 1][j - 1])
            if grid[i - 1][j - 1] > 0:
                dp[i][j][1] = max(dp[i][j - 1][0] + grid[i - 1][j - 1], dp[i][j][1])
                dp[i][j][2] = max(dp[i][j - 1][1] + grid[i - 1][j - 1], dp[i][j][2])
                dp[i][j][3] = max(dp[i][j - 1][2] + grid[i - 1][j - 1], dp[i][j][3])
    return max(dp[R][C])


if __name__ == '__main__':
    print(solve())
