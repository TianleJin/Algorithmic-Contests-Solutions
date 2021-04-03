from collections import defaultdict
it = lambda: list(map(int, input().strip().split()))
INF = float('inf')


def solve():
    N, K = it()
    H = it()

    P = [[0] * N for _ in range(N)]
    for i, h in enumerate(H):
        c = defaultdict(int)
        f = c[h] = 1
        for j in range(i + 1, N):
            c[H[j]] += 1
            f = max(f, c[H[j]])
            P[i][j] = j - i - f + 1
    
    dp1 = [0] * (N + 1)
    for i in range(N):
        dp1[i + 1] = P[0][i]
    
    ans = dp1[N]
    for k in range(1, K + 1):
        dp2 = [INF] * (N + 1)
        for j in range(k, N):
            for i in range(j + 1):
                dp2[j + 1] = min(dp2[j + 1], dp1[i] + P[i][j])
        dp1 = dp2
        ans = min(ans, dp1[N])
    return ans


if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))