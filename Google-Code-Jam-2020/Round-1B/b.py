it = lambda: list(map(int, input().strip().split()))


R = 10 ** 9 // 2
TRY = [
    [-R, R],
    [0, R],
    [R, R],
    [-R, 0],
    [0, 0],
    [R, 0],
    [-R, -R],
    [0, -R],
    [R, -R]
]


def query():
    ok = False
    for x, y in TRY:
        print(x, y, flush=True)
        res = input().strip()
        if res == 'CENTER':
            return True
        elif res == 'HIT':
            ok = True
            break
        elif res == 'MISS':
            continue
        elif res == 'WRONG':
            return False
        else:
            assert False
    if not ok:
        return False

    # search for left boundary
    lo = -(10 ** 9)
    hi = x
    while lo < hi:
        mid = (lo + hi) // 2
        print(mid, y, flush=True)
        res = input().strip()
        if res == 'CENTER':
            return True
        elif res == 'HIT':
            hi = mid
        elif res == 'MISS':
            lo = mid + 1
        elif res == 'WRONG':
            return False
        else:
            assert False
    left = lo

    # search for right boundary
    lo = x
    hi = 10 ** 9
    while lo < hi:
        mid = (lo + hi + 1) // 2
        print(mid, y, flush=True)
        res = input().strip()
        if res == 'CENTER':
            return True
        elif res == 'HIT':
            lo = mid
        elif res == 'MISS':
            hi = mid - 1
        elif res == 'WRONG':
            return False
        else:
            assert False
    right = lo


    # search for top boundary
    lo = y
    hi = 10 ** 9
    while lo < hi:
        mid = (lo + hi + 1) // 2
        print(x, mid, flush=True)
        res = input().strip()
        if res == 'CENTER':
            return True
        elif res == 'HIT':
            lo = mid
        elif res == 'MISS':
            hi = mid - 1
        elif res == 'WRONG':
            return False
        else:
            assert False
    top = lo

    # search for bottom boundary 
    lo = -(10 ** 9)
    hi = y
    while lo < hi:
        mid = (lo + hi) // 2
        print(x, mid, flush=True)
        res = input().strip()
        if res == 'CENTER':
            return True
        elif res == 'HIT':
            hi = mid
        elif res == 'MISS':
            lo = mid + 1
        elif res == 'WRONG':
            return False
        else:
            assert False
    bottom = lo

    x1 = (left + right) // 2
    y1 = (top + bottom) // 2
    for x in [x1, x1 - 1, x1 + 1, x1 - 2, x1 + 2, x1 - 3, x1 + 3]:
        for y in [y1, y1 - 1, y1 + 1, y1 - 2, y1 + 2, y1 - 3, y1 + 3]:
            print(x, y, flush=True)
            res = input().strip()
            if res == 'CENTER':
                return True
            elif res == 'WRONG':
                return False
            else:
                continue
    

if __name__ == '__main__':
    T, _, _ = it()
    for _ in range(T):
        if not query():
            break