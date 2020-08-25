from collections import defaultdict
it = lambda: list(map(int, input().strip().split()))
INF = float('inf')
MOD = 10 ** 9 + 7


def solve():
    N, A, B, C = it()

    if A + B - C > N:
        return ''

    for a in [A, B, C]:
        if a == 0 or a > N:
            return ''
    
    if N == 1:
        if A == B == C == 1:
            return '1'
        else:
            return ''
    
    if N == 2:
        if A == B == C == 2:
            return '1 1'
        elif A == 1 and B == 2 and C == 1:
            return '2 1'
        elif A == 2 and B == 1 and C == 1:
            return '1 2'
        else:
            return ''
    
    if A == B == C == 1:
        return ''
        
    ans = [0] * N

    i = 0
    for _ in range(max(0, A - C - 1)):
        ans[i] = 1
        i += 1
    if A - C > 0:
        ans[i] = 2
        i += 1
    
    j = N - 1
    for _ in range(max(0, B - C - 1)):
        ans[j] = 1
        j -= 1
    if B - C > 0:
        ans[j] = 2
        j -= 1

    if C == 1:
        if A <= B:
            ans[i] = N
            i += 1
        else:
            ans[j] = N
            j -= 1
        for k in range(i, j + 1):
            ans[k] = 1
    else:
        for k in range(C):
            if k % 2 == 1:
                ans[i] = N
                i += 1
            else:
                ans[j] = N
                j -= 1
        for k in range(i, j + 1):
            ans[k] = 1
    return ' '.join(map(str, ans))


if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        if ans:
            print('Case #{}: {}'.format(tt, ans))
        else:
            print('Case #{}: IMPOSSIBLE'.format(tt))