# Task: Given an array, partition the array into k subarrays such that the sum of each subarray is as close as possible.
INF = float('inf')


def partitionArray(arr, k):
    n = len(arr)
    if n < k:
        return False
    
    presum = [0] * (n + 1)
    for i in range(n):
        presum[i + 1] = presum[i] + arr[i]
    
    total = presum[n]
    target = total / k

    dp = [[INF] * (n + 1) for cut in range(k + 1)]
    dp[0][0] = 0

    for par in range(k):
        for i in range(par + 1, n + 1):
            for j in range(i):
                dp[par + 1][i] = min(dp[par + 1][i], dp[par][j] + (presum[i] - presum[j] - target) ** 2)

    i = n
    par = k
    partitions = [[] for _ in range(k)]
    while par > 0 and i > 0:
        par -= 1
        while i > 0 and dp[par][i] >= dp[par][i - 1]:
            i -= 1
            partitions[par].append(arr[i])
        partitions[par] = partitions[par][::-1]
    return partitions


# TODO brute force
if __name__ == "__main__":
    case = [1, 5, 4, 3, 2, 5, 4, 3]
    k = 3
    print(partitionArray(case, k))