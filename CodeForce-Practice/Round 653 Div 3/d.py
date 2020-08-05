from collections import defaultdict
it = lambda: list(map(int, input().strip().split()))


def solve():
    n, k = it()
    A = it()
    m = defaultdict(int)

    ans = 0
    for i in range(n):
        r = k - A[i] % k
        if r == k:
            continue
        ans = max(ans, m[r] * k + r + 1)
        m[r] += 1
    print(ans)


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solve()