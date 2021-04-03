from collections import deque, defaultdict
from heapq import heapify, heappop, heappush
it = lambda: list(map(int, input().strip().split()))

def solve():
    p = 'abacaba'
    n = int(input())
    s = input().strip()

    cnt = 0
    for i in range(n):
        if i + 7 <= n:
            if s[i:i + 7] == p:
                cnt += 1

    if cnt > 1:
        return False

    if cnt == 1:
        return s.replace('?', 'z')

    s = list(s)
    for i in range(n):
        if i + 7 <= n:
            ok = True
            for j in range(i, i + 7):
                if s[j] == p[j - i] or s[j] == '?':
                    continue
                else:
                    ok = False
                    break
            if ok:
                idx = []
                for j in range(i, i + 7):
                    if s[j] == '?':
                        s[j] = p[j - i]
                        idx.append(j)

                ok1 = True
                for j in range(max(0, i - 8), i + 7):
                    if j != i:
                        if j + 7 <= n and ''.join(s[j:j + 7]) == p:
                            ok1 = False
                            break
                
                if not ok1:
                    for k in idx:
                        s[k] = '?'
                else:
                    return ''.join(s).replace('?', 'z')
    return False


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        a = solve()
        if a is False:
            print('NO')
        else:
            print('YES')
            print(a)