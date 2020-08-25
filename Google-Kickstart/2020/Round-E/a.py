from collections import defaultdict
it = lambda: list(map(int, input().strip().split()))
INF = float('inf')
MOD = 10 ** 9 + 7


def solve():
    N = int(input())
    A = it()
    ans = 2
    cur = 2
    last = A[1] - A[0]
    for i in range(2, N):
        if A[i] - A[i - 1] != last:
            ans = max(ans, cur)
            cur = 2
            last = A[i] - A[i - 1]
        else:
            cur += 1
    ans = max(ans, cur)
    return ans


if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))