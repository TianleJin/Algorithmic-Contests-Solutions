def solve(mat, N, t):
    trace = 0
    for i in range(N):
        trace += mat[i][i]
    
    row_cnt = 0
    for i in range(N):
        seen = set()
        for j in range(N):
            if mat[i][j] in seen:
                row_cnt += 1
                break
            seen.add(mat[i][j])

    col_cnt = 0
    for j in range(N):
        seen = set()
        for i in range(N):
            if mat[i][j] in seen:
                col_cnt += 1
                break
            seen.add(mat[i][j])
    
    print("Case #{}: {} {} {}".format(t, trace, row_cnt, col_cnt))


if __name__ == "__main__":
    T = int(input())
    for t in range(1, T + 1):
        N = int(input())
        matrix = [[int(num) for num in input().strip().split()] for _ in range(N)]
        solve(matrix, N, t)
