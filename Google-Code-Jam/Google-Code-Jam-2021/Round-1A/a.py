it = lambda: list(map(int, input().strip().split()))


T = int(input())
for tt in range(1, T + 1):
    n = int(input())
    ans = 0
    arr = it()
    for i in range(1, n):
        if arr[i] > arr[i - 1]:
            continue

        s1 = str(arr[i - 1])
        c1 = len(s1)
        
        s2 = str(arr[i])
        c2 = len(s2)

        if c1 == c2:
            ans += 1
            arr[i] = int(s2 + '0')
            continue
        
        l = min(c1, c2)
        if int(s2[:l]) < int(s1[:l]):
            ans += c1 - c2 + 1
            arr[i] = int(s2 + '0' * (c1 - c2 + 1))
            continue

        if int(s2[:l]) > int(s1[:l]):
            ans += c1 - c2
            arr[i] = int(s2 + '0' * (c1 - c2))
            continue

        suf = s1[l:]
        l = len(suf)
        if suf.count('9') == l:
            ans += l + 1
            arr[i] = int(s2 + '0' * (l + 1))
        else:
            ext = str(int(suf) + 1)
            ext = '0' * (l - len(ext)) + ext
            ans += len(ext)
            arr[i] = int(s2 + ext)
        
    print("Case #{}: {}".format(tt, ans))