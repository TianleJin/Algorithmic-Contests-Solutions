def solve():
    n = int(input())
    
    s = 'codeforces'
    a = [1] * 10
    
    i = 0
    c = 1
    while c < n:
        c //= a[i]
        a[i] += 1
        c *= a[i]
        i = (i + 1) % 10
    return ''.join(a[j] * s[j] for j in range(10))
    


if __name__ == '__main__':
    print(solve())