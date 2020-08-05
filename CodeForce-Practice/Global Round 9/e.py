it = lambda: list(map(int, input().strip().split()))


def solve():
    N = int(input())
    A = it()

    inversions = []
    for i in range(N):
        inversion = []
        for j in range(i):
            if A[j] > A[i]:
                inversion.append(j)
        inversions.append(inversion)
    
    R = []
    B = [[a, i] for i, a in enumerate(A)]
    for i in range(N - 1, -1, -1):
        inversion = inversions[i]
        inversion.sort(key=lambda x:B[x])
        for j in inversion:
            R.append([j + 1, i + 1])
            B[i], B[j] = B[j], B[i]
    
    print(len(R))
    for i, j in R:
        print(i, j)


if __name__ == '__main__':
    solve()