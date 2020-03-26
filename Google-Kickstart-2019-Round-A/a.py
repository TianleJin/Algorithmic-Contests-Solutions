from collections import deque


def parse():
    r, c = input().strip().split()
    r, c = int(r), int(c)
    mat = [[0] * c for _ in range(r)]
    for r0 in range(r):
        t = input().strip()
        for idx, ch in enumerate(t):
            mat[r0][idx] = int(ch)
    return r, c, mat

def withinK(k, r, c, dist, mat):
    plus = []
    minus = []
    for r0 in range(r):
        for c0 in range(c):
            if dist[r0][c0] > k:
                plus.append(r0 + c0)
                minus.append(r0 - c0)

    if not plus:
        return True
    
    min_minus = min(minus)
    max_minus = max(minus)
    min_plus = min(plus)
    max_plus = max(plus)

    for r0 in range(r):
        for c0 in range(c):
            if not mat[r0][c0]:
                max_distance = max(abs(min_plus - (r0 + c0)), abs(max_plus - (r0 + c0)), abs(min_minus - (r0 - c0)), abs(max_minus - (r0 - c0))) 
                if max_distance <= k:
                    return True
    return False

def solve(r, c, mat):
    queue = deque()
    dist = [[float('inf')] * c for _ in range(r)]
    for r0 in range(r):
        for c0 in range(c):
            if mat[r0][c0]:
                dist[r0][c0] = 0
                queue.append((r0, c0))
    curr = 0
    while queue:
        curr += 1
        for _ in range(len(queue)):
            r0, c0 = queue.popleft()
            for r1, c1 in ((r0 + 1, c0), (r0 - 1, c0), (r0, c0 + 1), (r0, c0 - 1)):
                if 0 <= r1 < r and 0 <= c1 < c and dist[r1][c1] == float('inf'):
                    dist[r1][c1] = curr
                    queue.append((r1, c1))
    
    left, right = 0, r + c
    while left < right:
        k = (left + right) // 2
        if withinK(k, r, c, dist, mat):
            right = k
        else:
            left = k + 1
    return left
        
if __name__ == "__main__":
    n = int(input())
    for i in range(1, n + 1):
        r, c, mat = parse()
        ans = solve(r, c, mat)
        print("Case #{}: {}".format(i, ans))
