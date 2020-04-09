import collections

def solve(r, c):
    ban = [[set() for _ in range(c)] for _ in range(r)]
    for i in range(r):
        for j in range(c):
            for k in range(r):
                ban[k][j].add((i, j))
            for l in range(c):
                if l != j:
                    ban[i][l].add((i, j))
            f = min(i, j)
            while 0 <= i - f < r and 0 <= j - f < c:
                if f != 0:
                    ban[i - f][j - f].add((i, j))
                f -= 1
            g = min(i, c - j - 1)
            while 0 <= i - g < r and 0 <= j + g < c:
                if g != 0:
                    ban[i - g][j + g].add((i, j))
                g -= 1
    
    ans = []
    vis = set()
    def dfs(i, j):
        ans.append((i, j))
        vis.add((i, j))

        if len(ans) == r * c:
            return True

        most = 0
        next_ = (-1, -1)

        for k in range(r):
            for l in range(c):
                if (k, l) not in vis and (k, l) not in ban[i][j]:
                    val = len(ban[k][l] - vis)
                    if val > most:
                        most = val
                        next_ = (k, l)
        if next_ == (-1, -1):
            return False
        
        dfs(*next_)

    dfs(r // 2, c // 2)
    return ans


if __name__ == '__main__':
    T = int(input())
    for t in range(1, T + 1):
        r, c = input().strip().split()
        r, c = int(r), int(c)
        ans = solve(r, c)
        if len(ans) != r * c:
            print("Case #{}: IMPOSSIBLE".format(t))
        else:
            print("Case #{}: POSSIBLE".format(t))
            for i, j in ans:
                print(i + 1, j + 1)