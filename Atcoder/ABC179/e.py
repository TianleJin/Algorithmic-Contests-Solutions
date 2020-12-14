from collections import defaultdict
it = lambda: list(map(int, input().strip().split()))


def solve():
    N, X, M = it()
    if N == 1: return X % M

    cur = 0
    cnt = 0
    value = defaultdict(int)
    history = defaultdict(int)
    for i in range(N):
        if X in history: break
        value[X] = cur
        history[X] = i
        cnt += 1
        cur += X
        X = X * X % M
        
    loop = cur - value[X]
    period = i - history[X]
    freq, rem = divmod(N - cnt, period)
    cur += freq * loop
    for i in range(rem):
        cur += X
        X = X * X % M
    return cur


if __name__ == '__main__':
    print(solve())