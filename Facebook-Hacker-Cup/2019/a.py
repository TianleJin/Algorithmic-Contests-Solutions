from random import randint
it = lambda: list(map(int, input().strip().split()))
INF = float('inf')


def case():
    print(500)
    print(100000)
    for _ in range(499):
        print(randint(1, 100000))


def search(K):
    lo = 1
    hi = K
    while lo < hi:
        mi = (lo + hi + 1) >> 1
        if mi * (mi + 1) // 2 > K:
            hi = mi - 1
        else:
            lo = mi
    return lo


def solve():
    a = ''
    K = int(input())

    # use A
    l1 = search(K)
    a += 'A' * l1
    K -= (l1 + 1) * l1 // 2

    if K == 0:
        return a

    # use B
    l2 = search(K)
    a += 'B' * l2
    K -= (l2 + 1) * l2 // 2

    if K == 0:
        return a

    # use CDE
    assert 1000 - len(a) >= K

    a += 'CDE' * (K // 3)
    K = K % 3

    # use FG
    if K % 3 == 2:
        a += 'FG'
    elif K % 3 == 1:
        a += 'F'
    return a


if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))
    # case()