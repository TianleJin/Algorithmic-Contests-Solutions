def solve(n, animals):
    ok = True
    if animals[0] != animals[n - 1]:
        ok = False

    i = 1
    while ok and i < n:
        if animals[i - 1] != animals[i]:
            ok = False
        i += 1

    if ok:
        return 1, ['1'] * n
    
    dp = [[False] * 2 for _ in range(n)]
    dp[0][0] = True 
    for i in range(1, n):
        if animals[i] != animals[i - 1]:
            dp[i][0] = dp[i - 1][1]
            dp[i][1] = dp[i - 1][0]
        else:
            dp[i][0] = dp[i - 1][1] | dp[i - 1][0]
            dp[i][1] = dp[i - 1][1] | dp[i - 1][0]

    if dp[n - 1][1] or (dp[n - 1][0] and animals[0] == animals[n - 1]):
        ans = ['1'] * n
        j = '2' if dp[n - 1][1] else '1'
        ans[n - 1] = j
        for i in range(n - 2, -1, -1):
            if animals[i + 1] == animals[i] and dp[i][int(j) - 1]:
                ans[i] = j
            else:
                j = str(3 - int(j))
                ans[i] = j
        return 2, ans

    ans = ['1'] * n
    ans[0] = '3'
    for i in range(1, n, 2):
        ans[i] = '2'
    return 3, ans


if __name__ == "__main__":
    for _ in range(int(input())):
        n = int(input())
        animals = [int(num) for num in input().strip().split()]
        color, ans = solve(n, animals)
        print(color)
        print(' '.join(ans))