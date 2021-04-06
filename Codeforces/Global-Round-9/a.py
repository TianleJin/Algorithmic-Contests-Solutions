it = lambda: list(map(int, input().strip().split()))

def solve():
    N = int(input())
    A = it()
    for i in range(N):
        if i % 2:
            A[i] = -abs(A[i])
        else:
            A[i] = abs(A[i])
    return ' '.join(map(str, A))


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        print(solve())