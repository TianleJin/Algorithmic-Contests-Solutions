def parse():
    N, B = input().strip().split()
    N, B = int(N), int(B)
    prices = [int(num) for num in input().strip().split()]
    return N, B, prices

def solve(N, B, prices):
    prices.sort()
    cnt = 0
    i = 0
    while i < N and prices[i] <= B:
        B -= prices[i]
        i += 1
        cnt += 1
    return cnt

# Number of test cases
T = int(input())
for t in range(1, T + 1):
    N, B, prices = parse()
    ans = solve(N, B, prices)
    print("Case #{}: {}".format(t, ans))