from collections import defaultdict
from random import randint
from itertools import combinations
it = lambda: list(map(int, input().strip().split()))
INF = float('inf')


def case(T, ub):
    print(T)
    for _ in range(T):
        N, S = randint(2, ub), randint(1, 1000)
        print(N, S)
        for _ in range(N):
            skills = []
            c = randint(1, min(S, 5))
            while len(skills) < c:
                s = randint(1, S)
                if not s in skills:
                    skills.append(s)
            skills = [c] + skills
            print(' '.join(map(str, skills)))


def brute(N, E):
    for i in range(N):
        E[i] = set(E[i])
    
    ans = 0
    for i in range(N):
        for j in range(i + 1, N):
            if len(E[i].difference(E[j])) > 0:
                ans += 1
            if len(E[j].difference(E[i])) > 0:
                ans += 1
    return ans


def solve():
    N, _ = it()
    E = []
    C = defaultdict(int)

    for _ in range(N):
        e = sorted(it()[1:])
        E.append(e)
        for r in range(1, len(e) + 1):
            for c in combinations(e, r):
                C[tuple(c)] += 1
    
    ans = N * N
    for e in E:
        ans -= C[tuple(e)]
    # assert ans == brute(N, E)
    return ans


if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))
    # case(100, 5 * 10 ** 4)