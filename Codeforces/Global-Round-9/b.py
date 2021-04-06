it = lambda: list(map(int, input().strip().split()))


def count(G, M, N, i, j):
    num = 0
    pos = 0
    for x, y in ((i + 1, j), (i - 1, j), (i, j - 1), (i, j + 1)):
        if 0 <= x < M and 0 <= y < N:
            num += 1
            if G[x][y] > 0:
                pos += 1
    return num, pos


def broadcast(G, M, N, i, j, k):
    for x, y in ((i + 1, j), (i - 1, j), (i, j - 1), (i, j + 1)):
        if k == 0:
            break
        if 0 <= x < M and 0 <= y < N and G[x][y] == 0:
            _, pos = count(G, M, N, x, y)
            G[x][y] = pos
            fix(G, M, N, x, y)
            k -= 1


def fix(G, M, N, i, j):
    for x, y in ((i + 1, j), (i - 1, j), (i, j - 1), (i, j + 1)):
        if 0 <= x < M and 0 <= y < N and G[x][y] > 0:
            _, pos = count(G, M, N, x, y)
            if pos > G[x][y]:
                G[x][y] = pos


def solve():
    M, N = it()
    G = [it() for _ in range(M)]
    for r in range(M):
        for c in range(N):
            if G[r][c] > 0:
                num, pos = count(G, M, N, r, c)
                if G[r][c] == pos:
                    continue
                elif G[r][c] > pos:
                    if G[r][c] > num:
                        return None
                    broadcast(G, M, N, r, c, G[r][c] - pos)
                elif G[r][c] < pos:
                    G[r][c] = pos
    return G


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        ans = solve()
        if ans is None:
            print('NO')
        else:
            print('YES')
            for row in ans:
                print(' '.join(map(str, row)))