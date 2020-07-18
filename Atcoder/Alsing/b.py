it = lambda: list(map(int, input().strip().split()))


def solve():
    N = int(input())
    A = it()
    cnt = 0
    for i in range(N):
        if i % 2 == 0 and A[i] % 2:
            cnt += 1
    print(cnt)

solve()