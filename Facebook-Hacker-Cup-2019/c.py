from collections import defaultdict
from random import randint
it = lambda: list(map(int, input().strip().split()))
INF = float('inf')


def case(N, M):
    print(N, M)
    for _ in range(N):
        print(''.join('Y' if randint(0, 1) == 1 else 'N' for _ in range(M)))


def solve():
    # N people 
    # M questions
    N, M = it()
    A = [input().strip() for _ in range(N)]

    ye = []
    no = []
    for i in range(M):
        if A[0][i] == 'Y':
            ye.append(i)
        else:
            no.append(i)

    # count supersets
    ss = 0
    for i in range(1, N):
        if all(A[i][j] == 'Y' for j in ye):
            ss += 1
    
    if ss > 1:
        return 'N'

    if ss == 1:
        return 'Y'

    # check if there is a question where only 1 person got
    for j in no:
        c = 0
        for i in range(1, N):
            if A[i][j] == 'Y':
                c += 1
        if c == 1:
            return 'Y'
    
    # P = defaultdict(set)
    # Q = defaultdict(set)

    # for i in range(N):
    #     for j in range(M):
    #         if A[i][j] == 'Y':
    #             P[i].add(j)
    #             Q[j].add(i)

    for i in range(1, N):
        I = set()
        L = set()
        for j in range(M):
            if A[0][j] == A[i][j] == 'Y':
                I.add(j)
        
        for l in range(1, N):
            if i != l and all(A[l][j] == 'Y' for j in I):
                L.add(l)
        
        for j in range(M):
            if A[i][j] == 'Y' and A[0][j] == 'N':
                if not L or all(A[l][j] == 'N' for l in L):
                    return 'Y'
    return 'N'
                

if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))

    # print(200)
    # case(400, 400)
    # for _ in range(199):
    #     case(randint(2, 400), randint(1, 400))