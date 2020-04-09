def solve(N, M):
    modulo = []
    for num in ['3', '4', '5', '7', '11', '13', '17']:
        print(' '.join([num] * 18), flush=True)
        modulo.append(sum(int(i) for i in input().strip().split()) % int(num))

    for i in range(M + 1):
        okay = True
        for base, mod in zip([3, 4, 5, 7, 11, 13, 17], modulo):
            if i % base != mod:
                okay = False
                break
        if okay:
            print(i, flush=True)
            return input()


if __name__ == "__main__":
    T, N, M = input().strip().split()
    T, N, M = int(T), int(N), int(M)
    for t in range(1, T + 1):
        solve(N, M)