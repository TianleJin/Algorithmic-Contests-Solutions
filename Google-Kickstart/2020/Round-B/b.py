def solve():
    N, D = input().strip().split()
    N, D = int(N), int(D)
    X = list(map(int, input().strip().split()))

    limit = D
    for i in range(N - 1, -1, -1):
        x = X[i]
        if x == 1:
            continue
        limit = (limit // x) * x
    return limit


if __name__ == "__main__":
    T = int(input())
    for t in range(1, T + 1):
        print('Case #{}: {}'.format(t, solve()))