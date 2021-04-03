from random import randint
it = lambda: list(map(int, input().strip().split()))


def div(x):
    return x // 2 if x >= 0 else -(abs(x) // 2)


def case():
    print(randint(-100, 100), randint(-100, 100))


def check(S, X, Y):
    x = 0
    y = 0
    i = 1
    for ch in S:
        if ch == 'N':
            y += i
        elif ch == 'S':
            y -= i
        elif ch == 'W':
            x -= i
        else:
            x += i
        i = i << 1
    assert X == x and Y == y


def solve():
    A = []
    X, Y = it()
    # X1, Y1 = X, Y

    while X != 0 or Y != 0:
        if X % 2 == Y % 2:
            return 'IMPOSSIBLE'
        elif X % 2 == 1:
            x1, y1 = div(X + 1), div(Y)
            x2, y2 = div(X - 1), div(Y)
            if x1 == y1 == 0:
                X, Y = x1, y1
                A.append('W')
                continue
            if x2 == y2 == 0:
                X, Y = x2, y2
                A.append('E')
                continue
            if x1 % 2 != y1 % 2:
                X, Y = x1, y1
                A.append('W')
                continue
            else:
                X, Y = x2, y2
                A.append('E')
                continue
        else:
            x1, y1 = div(X), div(Y + 1)
            x2, y2 = div(X), div(Y - 1)
            if x1 == y1 == 0:
                X, Y = x1, y1
                A.append('S')
                continue
            if x2 == y2 == 0:
                X, Y = x2, y2
                A.append('N')
                continue
            if x1 % 2 != y1 % 2:
                X, Y = x1, y1
                A.append('S')
                continue
            else:
                X, Y = x2, y2
                A.append('N')
                continue

    # check(''.join(A), X1, Y1) 
    return ''.join(A)


if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))
    
    # for _ in range(1000):
    #     case()