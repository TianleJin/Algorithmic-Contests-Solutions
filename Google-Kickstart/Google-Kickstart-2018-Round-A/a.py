it = lambda: list(map(int, input().strip().split()))


def change(N, k, less=True):
    s = list(N)
    s[k] = str(int(s[k]) - 1 if less else int(s[k]) + 1)
    for i in range(k + 1, len(s)):
        s[i] = '8' if less else '0'
    return abs(int(''.join(s)) - int(N))


def solve():
    N = input().strip()
    for k in range(len(N)):
        if int(N[k]) % 2:
            return change(N, k) if N[k] == '9' else min(change(N, k), change(N, k, False))
    return 0


if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))