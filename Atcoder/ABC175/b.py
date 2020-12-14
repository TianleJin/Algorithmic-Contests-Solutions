it = lambda: list(map(int, input().strip().split()))

def solve():
    N = int(input())
    L = it()
    ans = 0
    for i in range(N):
        for j in range(i + 1, N):
            for k in range(j + 1, N):
                if L[i] != L[j] and L[j] != L[k] and L[i] != L[k] and L[i] + L[j] > L[k] and L[i] + L[k] > L[j] and L[k] + L[j] > L[i]:
                    ans += 1
    return ans


if __name__ == '__main__':
    ans = solve()
    print(ans)