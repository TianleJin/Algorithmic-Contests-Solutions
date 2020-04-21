# cook your dish here
def solve(N, prices):
    M = 10 ** 9 + 7
    prices.sort()
    ans = 0
    for i in range(N):
        ans = (ans + max(0, prices[i] - (N - i - 1))) % M
    print(ans)


T = int(input())
for _ in range(T):
    N = int(input())
    prices = list(map(int, input().strip().split()))
    solve(N, prices)