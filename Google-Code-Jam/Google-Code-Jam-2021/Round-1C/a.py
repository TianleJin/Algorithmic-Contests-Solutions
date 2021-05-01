it = lambda: list(map(int, input().strip().split()))


def solve():
    n, k = it()
    nums = it()
    nums.sort()
    win = []
    win.append(nums[0] - 1)
    win.append(k - nums[-1])
    for i in range(n - 1):
        win.append((nums[i + 1] - nums[i]) // 2)
    win.sort()
    ans = win[-1] + win[-2]
    for i in range(n - 1):
        ans = max(ans, nums[i + 1] - nums[i] - 1)
    return ans / k


T = int(input())
for tt in range(1, T + 1):
    ans = solve()
    print("Case #{}: {}".format(tt, ans))