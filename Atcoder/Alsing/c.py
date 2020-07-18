
def solve():
    N = int(input())
    A = [0] * (N + 1)
    for x in range(1, 101):
        for y in range(1, 101):
            for z in range(1, 101):
                s = x * x + y * y + z * z + x * y + x * z + y * z
                if s <= N:
                    A[s] += 1
    for i in range(1, N + 1):
        print(A[i])

solve()