from collections import Counter


def solve(t):
    
    int(input())

    R = []
    unique = set()
    
    for _ in range(10000):
        _, r = input().strip().split()
        R.append(r)
        for ch in r:
            unique.add(ch)

    C = Counter([num[0] for num in R])
    for ch in unique:
        if not ch in C:
            return ch + ''.join(sorted(C.keys(), key=lambda x:C[x], reverse=True))
            

if __name__ == '__main__':
    T = int(input())
    for t in range(1, T + 1):
        print('Case #{}: {}'.format(t, solve(t)))