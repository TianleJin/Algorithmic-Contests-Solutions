it = lambda: list(map(int, input().strip().split()))

def solve():
    S = input().strip()
    assert len(S) == 3
    if S[0] == S[1] == S[2] == 'R':
        return 3
    elif S[0] == S[1] == 'R' or S[1] == S[2] == 'R':
        return 2
    elif S[0] == 'R' or S[1] == 'R' or S[2] == 'R':
        return 1
    return 0

if __name__ == '__main__':
    ans = solve()
    print(ans)