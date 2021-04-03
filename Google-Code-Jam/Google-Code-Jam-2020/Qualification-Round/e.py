from copy import deepcopy


def solve(N, k):
    if k < N or k > N * N:
        return False

    if k == N * N - 1 or k == N + 1:
        return False
    
    mat = [[0] * N for _ in range(N)]
    row_used = [set() for _ in range(N)]
    col_used = [set() for _ in range(N)]

    def dfs(i, j):
        if i == N and j == 0:
            trace = 0
            for i in range(N):
                trace += mat[i][i]
            return True if trace == k else False
        
        ban = row_used[i] | col_used[j]
        l, u, s = (N, 0, -1) if k > N * N // 2 else (1, N + 1, 1)
        for num in range(l, u, s):
            if num not in ban:
                mat[i][j] = num
                row_used[i].add(num)
                col_used[j].add(num)
                if dfs(i + 1 if j == N - 1 else i, 0 if j == N - 1 else j + 1):
                    return True
                mat[i][j] = 0
                row_used[i].discard(num)
                col_used[j].discard(num)
        return False

    if dfs(0, 0):
        return mat
    else:
        return False


if __name__ == "__main__":
    T = int(input())
    for t in range(1, T + 1):
        N, k = input().strip().split()
        N, k = int(N), int(k)
        mat = solve(N, k) 
        if mat is False:
            print("Case #{}: IMPOSSIBLE".format(t))
        else:
            print("Case #{}: POSSIBLE".format(t))
            for i in range(N):
                print(" ".join(str(num) for num in mat[i]))