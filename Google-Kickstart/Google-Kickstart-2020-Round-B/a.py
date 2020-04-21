def solve():
    n = int(input())
    h = list(map(int, input().strip().split()))

    cnt = 0
    for i in range(1, n - 1):
        if h[i - 1] < h[i] and h[i] > h[i + 1]:
            cnt += 1
    return cnt


if __name__ == "__main__":
    T = int(input())
    for t in range(1, T + 1):
        print('Case #{}: {}'.format(t, solve()))