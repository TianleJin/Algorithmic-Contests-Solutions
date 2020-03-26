def parse():
    N, K = input().strip().split()
    N, K = int(N), int(K)
    times = [int(num) for num in input().strip().split()]
    return N, K, times

def solve(N, K, times):
    lo, hi = 1, max(times[i + 1] - times[i] for i in range(N - 1))
    while lo < hi:
        mi = (lo + hi) >> 1
        k = 0
        for i in range(N - 1):
            d = times[i + 1] - times[i]
            k += (d + mi - 1) // mi - 1
        if k <= K:
            hi = mi
        else:
            lo = mi + 1
    return lo
   
# Number of test cases
T = int(input())
for t in range(1, T + 1):
    N, K, times = parse()
    ans = solve(N, K, times)
    print("Case #{}: {}".format(t, ans))