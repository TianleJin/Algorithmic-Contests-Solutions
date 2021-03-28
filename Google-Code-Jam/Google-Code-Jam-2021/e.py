N = 100
Q = 10000

T = int(input())
P = int(input())

for tt in range(1, T + 1):
    ans = [input().strip() for _ in range(N)]
    
    q = [0] * Q
    for i in range(N):
        for j in range(Q):
            if ans[i][j] == '1':
                q[j] += 1

    qord = list(range(Q))
    qord.sort(key=lambda i:q[i])

    score = [0] * N
    for i in range(N):
        inv = n0 = n1 = 0
        for j in range(Q - 1, -1, -1):
            if ans[i][qord[j]] == '1':
                inv += n0
                n1 += 1
            else:
                n0 += 1
        score[i] = inv / n0 / n1

    imposter = 0
    for i in range(1, N):
        if score[i] > score[imposter]:
            imposter = i
    print('Case #{}: {}'.format(tt, imposter + 1))

