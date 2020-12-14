from collections import deque, defaultdict
from heapq import heapify, heappop, heappush
it = lambda: list(map(int, input().strip().split()))

def solve():
    n = int(input())
    S = []
    for _ in range(n):
        S.append(input().strip())
    
    C = [0] * 26
    for s in S:
        for ch in s:
            C[ord(ch) - ord('a')] += 1
            
    ok = True
    for i in range(26):
        if C[i] % len(S) != 0:
            ok = False
    print("YES" if ok else "NO")


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solve()