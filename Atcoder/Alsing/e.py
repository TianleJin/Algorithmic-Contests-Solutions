from heapq import heappush, heappop
it = lambda: list(map(int, input().strip().split()))


def greedy(A):
    ans = 0
    A.sort(key=lambda x:x[0])
    pq = []
    for k, a, b in A:
        ans += a
        heappush(pq, [a - b, k, a, b])
        while len(pq) > k:
            ans -= heappop(pq)[0]
    return ans


def solve():
    N = int(input())

    prefer_late = []
    prefer_early = []
    for _ in range(N):
        k, a, b = it()
        if a >= b:
            prefer_early.append([k, a, b])
        else:
            prefer_late.append([N - k, b, a])
    
    ans = 0
    ans += greedy(prefer_early)
    ans += greedy(prefer_late)
    print(ans)


T = int(input())
for _ in range(T):
    solve()