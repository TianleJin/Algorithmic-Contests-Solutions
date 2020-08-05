it = lambda: list(map(int, input().strip().split()))


def solve():
    n = int(input())
    s = input().strip()

    ans = 0
    cur = 0
    for i in range(n):
        if s[i] == ')':
            cur -= 1
        else:
            cur += 1
        if cur < 0:
            ans += 1
            cur = 0
    print(ans)


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solve()