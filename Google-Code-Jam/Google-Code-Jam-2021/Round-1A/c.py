from fractions import Fraction
it = lambda: list(map(int, input().strip().split()))

T = int(input())
for tt in range(1, T + 1):
    N, Q = it()
    ans = [0] * N
    score = [0] * N
    for i in range(N):
        a, s = input().strip().split()
        score[i] = int(s)
        for j in range(Q):
            if a[j] == 'T':
                ans[i] ^= 1 << j
    
    p = []
    for msk in range(1 << Q):
        calc = [0] * N
        for j in range(N):
            for k in range(Q):
                if (ans[j] >> k & 1) == (msk >> k & 1):
                    calc[j] += 1
        if calc == score:
            p.append(msk)

    ret = []
    exp = Fraction()
    for i in range(Q):
        t = 0
        f = 0
        for msk in p:
            if msk >> i & 1:
                t += 1
            else:
                f += 1
        if t > f:
            ret.append('T')
            exp += Fraction(t, f + t)
        else:
            ret.append('F')
            exp += Fraction(f, f + t)

    print("Case #{}: {} {}/{}".format(tt, ''.join(ret), exp.numerator, exp.denominator))