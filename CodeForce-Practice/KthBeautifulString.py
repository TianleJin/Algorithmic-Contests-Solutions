def solve(n, k):
    first, second = n - 2, n - 1
    for i in range(n - 2, -1, -1):
        no = n - i - 1
        if no >= k:
            first = i
            second = n - k
            break
        else:
            k -= no

    ans = ['a'] * n
    ans[first] = 'b'
    ans[second] = 'b'
    return ''.join(ans)

if __name__ == "__main__":
    for _ in range(int(input())):
        n, k = input().strip().split()
        n = int(n)
        k = int(k)
        ans = solve(n, k)
        print(ans)