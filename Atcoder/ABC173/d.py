it = lambda: list(map(int, input().strip().split()))

def solve():
    N = int(input())
    A = it()
    if N == 1:
        return 0
        
    A.sort(reverse=True)

    ans = A[0]
    n = N - 2
    i = 1
    while n > 0:
        if n >= 2:
            ans += 2 * A[i]
            n -= 2
        else:
            ans += A[i]
            n -= 1
        i += 1
    return ans


if __name__ == '__main__':
    print(solve())