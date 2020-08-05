from collections import defaultdict

def solve():
    n = int(input())
    C = defaultdict(int)
    for _ in range(n):
        s = input().strip()
        C[s] += 1
    
    print('AC x', C['AC'])
    print('WA x', C['WA'])
    print('TLE x', C['TLE'])
    print('RE x', C['RE'])


if __name__ == '__main__':
    solve()