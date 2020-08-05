MOD = 10 ** 9 + 7
it = lambda: list(map(int, input().strip().split()))

def solve():
    N, K = it()
    A = it()
    
    zero = 0
    neg = []
    pos = []
    for i in range(N):
        if A[i] < 0:
            neg.append(A[i])
        elif A[i] > 0:
            pos.append(A[i])
        else:
            zero += 1
    
    if not neg and not pos:
        return 0
    
    pos.sort()
    neg.sort(reverse=True)

    if not pos and K % 2 == 1:
        if zero > 0:
            return 0

        ans = 1
        for i in range(K):
            ans = ans * neg[i] % MOD
        return ans

    ans = 1
    for _ in range(K >> 1):
        if len(pos) >= 2 and len(neg) >= 2:
            if neg[-1] * neg[-2] >= pos[-1] * pos[-2]:
                ans = ans * neg.pop() % MOD * neg.pop() % MOD
            else:
                ans = ans * pos.pop() % MOD * pos.pop() % MOD
        elif len(pos) >= 2:
            ans = ans * pos.pop() % MOD * pos.pop() % MOD
        elif len(neg) >= 2:
            ans = ans * neg.pop() % MOD * neg.pop() % MOD
        elif len(pos) == 1 and len(neg) == 1:
            ans = ans * pos.pop() % MOD * neg.pop() % MOD
        else:
            return 0
    
    if K % 2 == 1:
        if pos:
            ans = ans * pos.pop() % MOD
        elif neg:
            ans = ans * neg.pop() % MOD
        else:
            return 0
    if zero > 1 and ans < 0:
        return 0
    return ans


if __name__ == '__main__':
    print(solve())