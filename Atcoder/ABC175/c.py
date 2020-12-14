it = lambda: list(map(int, input().strip().split()))

def solve():
    X, K, D = it()
    X = abs(X)
    if X - K * D >= 0:
        return X - K * D
    K = K - X // D
    X = X - X // D * D
    assert K >= 0
    assert X >= 0
    return abs(X) if K % 2 == 0 else abs(X - D)


if __name__ == '__main__':
    ans = solve()
    print(ans)