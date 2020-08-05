it = lambda: list(map(int, input().strip().split()))


def solve():
    N = int(input())
    A = it()
    return A[0] < A[N - 1]


T = int(input())
for _ in range(T):
    if solve():
        print('YES')
    else:
        print('NO')