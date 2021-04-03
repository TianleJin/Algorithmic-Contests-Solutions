from collections import defaultdict
from random import randint
from bisect import bisect_left
it = lambda: list(map(int, input().strip().split()))


def case(total, ub):
    for _ in range(total):
        D, S = randint(1, ub), randint(1, ub)
        print(D, S)
        for _ in range(S):
            print(randint(1, 10 ** 4), randint(1, 10 ** 4))
        for _ in range(D):
            print(randint(1, 10 ** 8), randint(1, 10 ** 8))


def tset():
    print(100)
    case(90, 10 ** 3)
    case(10, 10 ** 5)


def isLess(x1, y1, x2, y2):
    assert x1 >= 0 and y1 >= 0 and x2 >= 0 and y2 >= 0
    return x1 * y2 <= x2 * y1


def possible(S, prefix, suffix, A, a, b):
    if a > prefix[S - 1] or b > suffix[S - 1]:
        return False

    lo = bisect_left(prefix, a)
    hi = bisect_left(suffix, b)
    if lo > S - hi - 1:
        return False
    elif lo < S - hi - 1:
        return True
    else:
        if lo > 0:
            a -= prefix[lo - 1]
        if hi > 0:
            b -= suffix[hi - 1]
        assert a >= 0 and b >= 0
        c, e = A[lo][1], A[lo][2]
        return isLess(a * e + b * c, c * e, 1, 1)


def solve():
    D, S = it()

    A = []
    for _ in range(S):
        c, e = it()
        A.append([c / e, c, e])
    A.sort(reverse=True)

    prefix = [0] * S
    prefix[0] = A[0][1]
    for i in range(1, S):
        prefix[i] = prefix[i - 1] + A[i][1]

    suffix = [0] * S
    suffix[0] = A[S - 1][2]
    for i in range(1, S):
        suffix[i] = suffix[i - 1] + A[S - i - 1][2]

    ans = []
    for _ in range(D):
        a, b = it()
        if possible(S, prefix, suffix, A, a, b):
            ans.append('Y')
        else:
            ans.append('N')
    return ''.join(ans)


if __name__ == '__main__':
    # tset()
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))