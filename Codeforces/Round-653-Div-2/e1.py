it = lambda: list(map(int, input().strip().split()))


def solve():
    n, k = it()
    
    bob = []
    both = []
    alice = [] 

    for _ in range(n):
        t, a, b = it()
        if a and b:
            both.append(t)
        elif a:
            alice.append(t)
        elif b:
            bob.append(t)
    
    M = len(both)
    N = min(len(bob), len(alice))

    if M + N < k:
        return -1

    bob.sort()
    both.sort()
    alice.sort()

    merge = [0] * N
    for i in range(N):
        merge[i] = alice[i] + bob[i]
    
    a = 0
    i = 0
    j = 0
    while k > 0 and (i < M or j < N):
        k -= 1
        if i >= M or (j < N and merge[j] < both[i]):
            a += merge[j]
            j += 1
        else:
            a += both[i]
            i += 1
    return a


if __name__ == '__main__':
    print(solve())