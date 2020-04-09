def solve(n):
    ans = n - 1
    for i in range(2, n // 2 + 1):
        j = n
        k = 0
        while i > 1 and j > 1:
            k += 1
            if j >= i:
                j -= i
            else:
                i -= j
        if i < 1 or j < 1:
            continue
        elif i == 1:
            ans = min(ans, k + j - 1)
        elif j == 1:
            ans = min(ans, k + i - 1)
    return ans


if __name__ == "__main__":
    ans = solve(int(input()))
    print(ans)