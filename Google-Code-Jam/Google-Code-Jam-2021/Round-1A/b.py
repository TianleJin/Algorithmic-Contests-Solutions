from random import randint

it = lambda: list(map(int, input().strip().split()))

T = int(input())

for tt in range(1, T + 1):
    m = int(input())

    total = 0
    prime = [0] * m
    count = [0] * m
    for i in range(m):
        p, n = it()
        prime[i] = p
        count[i] = n
        total += p * n
    
    prime = prime[::-1]
    count = count[::-1]
    
    ans = [0]
    def dfs(i, total, target):
        if total > target:
            return

        if total == target:
            ans[0] = max(ans[0], total)
            return

        if target <= ans[0]:
            return 

        if i == len(prime):
            return
        
        c = 1
        new_total = total
        new_target = target
        while c <= count[i]:
            new_total *= prime[i]
            new_target -= prime[i]
            dfs(i + 1, new_total, new_target)
            if new_total > new_target: break
            c += 1

        dfs(i + 1, total, target)

    dfs(0, 1, total)

    print("Case #{}: {}".format(tt, ans[0]))