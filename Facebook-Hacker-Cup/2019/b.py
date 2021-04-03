it = lambda: list(map(int, input().strip().split()))
INF = float('inf')


def solve():
    N, M = it()
    have = list(input().strip())
    need = list(input().strip())

    total = 0
    for i in range(N):
        s = 0
        r = l = M * (i + 1)
        while l > M * i and r > M * i:
            assert r <= l
            # already match
            if have[l] == need[l]:
                l -= 1
                r = min(r, l)
            # can swap to match
            elif need[l] == have[r]:
                have[l], have[r] = have[r], have[l]
                s += l - r
                l -= 1
            # move right pointer
            else:
                r -= 1
        assert r <= l
        while l > r:
            if have[l] != need[l]:
                s += l - r
            l -= 1
        total += s
    return total


if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))