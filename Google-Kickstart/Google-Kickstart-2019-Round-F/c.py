it = lambda: list(map(int, input().strip().split()))


def solve():
    A = it()
    for i in range(9):
        if A[i] > 11:
            A[i] = 11 if A[i] % 2 else 12

    limit = sum(A) >> 1
    total = sum(a * (i + 1) for i, a in enumerate(A)) % 11
    target = total >> 1 if total % 2 == 0 else (total + 11) >> 1

    def dfs(i, mod, cnt):
        if mod == target and cnt == limit:
            return True
        
        if i == 9 or cnt > limit:
            return False
        
        for c in range(A[i] + 1):
            if dfs(i + 1, (mod + c * (i + 1)) % 11, cnt + c):
                return True
        return False
    return 'YES' if dfs(0, 0, 0) else 'NO'


if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))