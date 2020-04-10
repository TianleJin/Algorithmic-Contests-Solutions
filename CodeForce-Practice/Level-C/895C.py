import math
from collections import defaultdict

M = 1e9 + 7
PRIMES = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67]

def squareSubsets(n, nums):
    power = [1] * (n + 1)
    primes = set()
    msks = dict()
    factors = defaultdict(list)
    cnt = defaultdict(int)
    memo = defaultdict(int)

    for num in nums:
        cnt[num] += 1

    for i in range(n):
        power[i + 1] = (power[i] * 2) % M
    
    for num in cnt:
        factors[num] = []
        k = num
        for prime in PRIMES:
            c = 0
            while k % prime == 0:
                c += 1
                k //= prime
            if c > 0:
                primes.add(prime)
            if c % 2:
                factors[num].append(prime)
            if k == 1:
                break
    
    index = dict((num, idx) for idx, num in enumerate(primes))
    
    for num in factors:
        msk = 0
        for prime in factors[num]:
            msk ^= 1 << index[prime]
        msks[num] = msk

    memo[0, 0] = 1
    for num, msk in msks.items():
        dp = defaultdict(int)
        for i, j in memo:
            dp[i + 1, j] = (dp[i + 1, j] + (power[cnt[num] - 1] * memo[i, j]) % M) % M
            dp[i + 1, j ^ msk] = (dp[i + 1, j ^ msk] + (power[cnt[num] - 1] * memo[i, j]) % M) % M
        memo = dp
    
    ans = memo[len(msks), 0]
    return int(ans) + M - 1 if ans < 0 else int(ans) - 1


if __name__ == "__main__":
    n = int(input())
    nums = [int(num) for num in input().strip().split()]
    ans = squareSubsets(n, nums)
    print(ans)