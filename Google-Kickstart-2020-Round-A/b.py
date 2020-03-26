def parse():
    N, K, P = input().strip().split()
    N, K, P = int(N), int(K), int(P)
    beauty = []
    for _ in range(N):
        b = [int(num) for num in input().strip().split()]
        beauty.append(b)
    return N, K, P, beauty

def solve(N, K, P, beauty):
    dp = [[0] * (P + 1) for _ in range(N + 1)]
    for i in range(1, N + 1):
        for j in range(1, P + 1):
            total = 0
            for k in range(min(K + 1, j + 1)):
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + total)
                if k < K:
                    total += beauty[i - 1][k]
    return dp[N][P]

# Number of test cases
T = int(input())
for t in range(1, T + 1):
    N, K, P, beauty = parse()
    ans = solve(N, K, P, beauty)
    print("Case #{}: {}".format(t, ans))