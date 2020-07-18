it = lambda: list(map(int, input().strip().split()))


def solve():
    L, R, d = it()

    cnt = 0
    for i in range(L, R + 1):
        if i % d == 0:
            cnt += 1
    print(cnt)


solve()