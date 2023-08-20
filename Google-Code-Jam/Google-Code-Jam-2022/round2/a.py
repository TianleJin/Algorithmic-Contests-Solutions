read_line = lambda: list(map(int, input().strip().split()))
INF = float('inf')

def print_impossible(tt):
    print(f"Case #{tt}: IMPOSSIBLE")

def print_answer(tt, ans):
    print(f"Case #{tt}: {len(ans)}")
    for x, y in ans:
        print(f"{x} {y}")

def shift_forward(j, l, c, s):
    nl = l + c + 1
    ns = s - 2
    nc = c - 1 if j % 2 == 0 else c
    nj = j + 1
    return nj, nl, nc, ns

def solve(tt):
    n, k = read_line()
    target_row = n // 2
    target_col = n // 2
    minimum_move = target_row + target_col
    
    if k < minimum_move or k % 2 == 1:
        print_impossible(tt)
        return

    ans = []
    diff = n * n - 1 - k
    j = 0
    l = 1
    c = n - 1
    s = 4 * (n - 1) - 2
    while diff > 0 and s > 0:
        if s <= diff:
            ans.append([l, l + s + 1])
            diff -= s
            for _ in range(4):
                j, l, c, s = shift_forward(j, l, c, s)
        else:
            j, l, c, s = shift_forward(j, l, c, s)
    print_answer(tt, ans)


if __name__ == "__main__":
    T = int(input())
    for tt in range(1, T + 1):
        solve(tt)
