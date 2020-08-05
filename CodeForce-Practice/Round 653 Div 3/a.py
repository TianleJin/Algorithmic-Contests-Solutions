it = lambda: list(map(int, input().strip().split()))


def solve():
    x, y, n = it()
    a = n // x * x + y
    while a > n:
        a -= x
    print(a) 


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solve()