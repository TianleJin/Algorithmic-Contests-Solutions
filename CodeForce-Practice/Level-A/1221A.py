import heapq
TARGET = 2048

def game2048(n, nums):
    nums = [num for num in nums if num <= TARGET]
    n = len(nums)
    if TARGET in nums:
        return "YES"
    
    heapq.heapify(nums)
    while nums:
        val = heapq.heappop(nums)
        if val == TARGET:
            return "YES"
        elif nums and nums[0] == val:
            heapq.heappop(nums)
            heapq.heappush(nums, val * 2)
    return "NO"


if __name__ == "__main__":
    Q = int(input())
    for q in range(Q):
        n = int(input())
        nums = [int(num) for num in input().strip().split()]
        ans = game2048(n, nums)
        print(ans)