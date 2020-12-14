it = lambda: list(map(int, input().strip().split()))


def solve():
    n = int(input())
    F = [0] * n
    S = [0] * n
    for i in range(n):
        a, b = it()
        F[i] = a
        S[i] = b
    
    cnt = 0
    for i in range(n):
        if F[i] == S[i]:
            cnt += 1
            if cnt == 3:
                return 'Yes'
        else:
            cnt = 0
    return 'No'


if __name__ == '__main__':
    print(solve())