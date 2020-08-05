it = lambda: list(map(int, input().strip().split()))


def getMex(N, C):
    for i in range(0, N):
        if C[i] == 0:
            return i
    return N


def solve():
    N = int(input())
    A = it()

    C = [0] * N
    for a in A:
        if a < N:
            C[a] += 1

    k = 0
    R = []

    while True:
        mex = getMex(N, C)
        if mex == N:
            break

        k += 1
        R.append(mex)

        if A[mex] < N:
            assert C[A[mex]] > 0
            C[A[mex]] -= 1
        
        A[mex] = mex
        C[mex] += 1
    
    for i in range(N):
        if A[i] == i:
            continue
            
        mex = A[i]
        A[i] = N
        k += 1
        R.append(i)

        while mex != N:
            k += 1
            R.append(mex)
            tmp = A[mex]
            A[mex] = mex
            mex = tmp
    
    print(k)
    print(' '.join(map(str, [i + 1 for i in R])))


T = int(input())
for _ in range(T):
    solve()