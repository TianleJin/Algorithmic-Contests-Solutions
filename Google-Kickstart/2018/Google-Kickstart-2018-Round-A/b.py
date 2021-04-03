from bisect import bisect_left
it = lambda: list(map(int, input().strip().split()))


def solve():
    N, K = it()
    V = it()
    V.sort()

    suffix = [0] * (N + 1)
    for i in range(N - 1, -1, -1):
        suffix[i] = V[i] + suffix[i + 1]
    
    dp = [0] * (K + 1)
    dp[0] = sum(V) / N
    for i in range(1, K + 1):
        k = bisect_left(V, dp[i - 1])
        dp[i] = (k * dp[i - 1] + suffix[k]) / N
    return dp[K]


if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))