import random
import sys

T, N, Q = list(map(int, input().strip().split()))

cnt = 0

def query(i, j, k):
    global cnt
    print(i, j, k, flush=True)
    cnt += 1
    res = int(input())
    if res == -1:
        sys.exit()
    return res

def submit(ans):
    assert len(ans) == N
    print(*ans, flush=True)
    res = int(input())
    if res == -1:
        sys.exit()
    assert res == 1

for tt in range(1, T + 1):
    ans = list(range(1, 3))
    for i in range(3, N + 1):
        l = 0
        r = len(ans)
        while l < r:
            if l + 1 == r:
                if l:
                    l -= 1
                else:
                    r += 1
            ml = (l + l + r) // 3
            mr = (l + r + r) // 3
            res = query(ans[ml], ans[mr], i)
            if res == ans[ml]:
                r = ml
            elif res == ans[mr]:
                l = mr + 1
            else:
                l = ml + 1
                r = mr
        ans.insert(l, i)
    submit(ans)