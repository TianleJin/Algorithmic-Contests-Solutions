from collections import deque
it = lambda: list(map(int, input().strip().split()))


def maximise(R, cycle):
    cur = 0
    L = len(cycle)
    ans = max(cycle)
    queue = deque([0])
    dp = [0] * (2 * L + 1)
    for i, num in enumerate(cycle + cycle):
        cur += num
        while queue and i + 1 - queue[0] > R:
            queue.popleft()
        if queue: 
            ans = max(ans, cur - dp[queue[0]])
        while queue and dp[queue[-1]] >= cur: 
            queue.pop()
        queue.append(i + 1)
        dp[i + 1] = cur
    return ans


def get(K, cycle):
    L = len(cycle)
    T = sum(cycle)
    B = (K - 1) // L if K > L else 0
    return max(maximise(K, cycle), maximise(K - B * L, cycle) + max(0, B * T))


def solve():
    N, K = it()
    P = it()
    C = it()

    for i in range(N):
        P[i] -= 1

    cycles = []
    seen = [False] * N
    for i in range(N):
        if not seen[i]:
            cycle = []
            first = curr = i
            while True:
                seen[curr] = True
                cycle.append(C[curr])
                curr = P[curr]
                if curr == first:
                    break
            cycles.append(cycle)
    
    ans = float('-inf')
    for cycle in cycles:
        ans = max(ans, get(K, cycle))
    return ans


if __name__ == '__main__':
    ans = solve()
    print(ans)