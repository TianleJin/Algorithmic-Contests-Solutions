from random import randint, random
from collections import defaultdict
it = lambda: list(map(int, input().strip().split()))


def case():
    N, G, M = randint(2, 10 ** 5), randint(1, 10 ** 5), randint(0, 10 ** 9)
    print(N, G, M)
    for _ in range(G):
        print(randint(1, N), 'C' if random() < 0.5 else 'A')


def solve():
    N, G, M = it()
    
    cw = defaultdict(list)
    acw = defaultdict(list)

    for i in range(G):
        s, o = input().strip().split()
        s = int(s)
        if o == 'C':
            e = (s + M) % N
            cw[e].append(i)
        else:
            e = (s - M) % N
            acw[e].append(i)

    cw_nearest = [None] * N
    
    curr = 0
    while True:
        if curr in cw:
            break
        curr = (curr + 1) % N
        if curr == 0:
            break
    
    if curr in cw:
        temp = curr
        last = curr
        while True:
            if last in cw:
                curr = last
            if curr is not None:
                dist = curr - last if curr >= last else curr + N - last
                if dist > M:
                    curr = None
            cw_nearest[last] = curr
            last = (last - 1) % N
            if last == temp:
                break
    
    acw_nearest = [None] * N

    curr = 0
    while True:
        if curr in acw:
            break
        curr = (curr - 1) % N
        if curr == 0:
            break
    
    if curr in acw:
        temp = curr
        last = curr
        while True:
            if last in acw:
                curr = last
            if curr is not None:
                dist = last - curr if last >= curr else last - curr + N
                if dist > M:
                    curr = None
            acw_nearest[last] = curr
            last = (last + 1) % N
            if last == temp:
                break
    
    ans = [0] * G
    for i in range(N):
        add1 = False
        add2 = False
        if cw_nearest[i] is not None and acw_nearest[i] is not None:
            dist1 = cw_nearest[i] - i if cw_nearest[i] >= i else cw_nearest[i] + N - i
            dist2 = i - acw_nearest[i] if i >= acw_nearest[i] else i + N - acw_nearest[i]
            if dist1 == dist2:
                add1 = True
                add2 = True
            elif dist1 < dist2:
                add1 = True
            else:
                add2 = True
        elif cw_nearest[i] is not None:
            add1 = True
        elif acw_nearest[i] is not None:
            add2 = True
        if add1:
            for g in cw[cw_nearest[i]]:
                ans[g] += 1
        if add2:
            for g in acw[acw_nearest[i]]:
                ans[g] += 1
                
    return ' '.join(map(str, ans))


if __name__ == '__main__':
    T = int(input())

    for tt in range(1, T + 1):
        ans = solve()
        print('Case #{}: {}'.format(tt, ans))

    # for _ in range(T):
    #     case()