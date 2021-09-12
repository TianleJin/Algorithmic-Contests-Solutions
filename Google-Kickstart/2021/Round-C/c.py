from functools import lru_cache

@lru_cache(None)
def dp(i=0, r=0, p=0, s=0):
    if i == 60:
        return 0, 0

    prob_r = 1 / 3 if i == 0 else s / i
    prob_p = 1 / 3 if i == 0 else r / i
    prob_s = 1 / 3 if i == 0 else p / i

    r_points = W * prob_s + E * prob_r + dp(i + 1, r + 1, p, s)[0]
    p_points = W * prob_r + E * prob_p + dp(i + 1, r, p + 1, s)[0]
    s_points = W * prob_p + E * prob_s + dp(i + 1, r, p, s + 1)[0]
    ret = max(r_points, p_points, s_points)
    return ret, 0 if r_points == ret else 1 if p_points == ret else 2
        
if __name__ == "__main__":
    T = int(input())
    X = int(input())
    for tt in range(1, T + 1):
        W, E = list(map(int, input().strip().split()))

        dp.cache_clear()
        dp()

        ans = []

        r = p = s = 0
        for i in range(60):
            if dp(i, r, p, s)[1] == 0:
                ans.append('R')
                r += 1
            elif dp(i, r, p, s)[1] == 1:
                ans.append('P')
                p += 1
            else:
                ans.append('S')
                s += 1

        ans = ''.join(ans)
        print("Case #{}: {}".format(tt, ans))