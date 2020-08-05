it = lambda: list(map(int, input().strip().split()))

def paint(G, H, W, a, b):
    ans = 0
    for i in range(H):
        if a & (1 << i):
            for j in range(W):
                if G[i][j] == '#' and b & (1 << j) == 0:
                    ans += 1
    return ans

def solve():
    ans = 0
    H, W, K = it()
    G = [input().strip() for _ in range(H)]
    for a in range(1 << H):
        for b in range(1 << W):
            if paint(G, H, W, a, b) == K:
                ans += 1
    return ans

if __name__ == '__main__':
    print(solve())