MXN = int(2e6)

def arithmetic(start, count):
    return (start + start + count - 1) * count // 2

if __name__ == "__main__":
    T = int(input())
    for tt in range(1, T + 1):
        G = int(input())
        ans = 0
        for c in range(1, MXN):
            if arithmetic(1, c) > G:
                break
            
            if (2 * G - c * c + c) % (2 * c) == 0:
                ans += 1
        print("Case #{}: {}".format(tt, ans))