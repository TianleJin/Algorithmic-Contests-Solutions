from collections import deque, defaultdict
it = lambda: list(map(int, input().strip().split()))

def solve():
    n, k = it()
    edges = defaultdict(set)
    vis = set()
    queue = deque()
    count = [[] for _ in range(n + 1)]

    for _ in range(n - 1):
        x, y = it()
        edges[x].add(y)
        edges[y].add(x)

    if k == 1:
        return n - 1

    for x in range(1, n + 1):
        if len(edges[x]) == 1:
            vis.add(x)
            queue.append(x)

    ans = 0
    while queue:
        x = queue.popleft()
        if edges[x]:
            for y in edges[x]:
                count[y].append(x)
                if len(count[y]) == k:
                    ans += 1
                    while count[y]:
                        edges[y].discard(count[y].pop())
                if len(edges[y]) == 1 and not y in vis:
                    vis.add(y)
                    queue.append(y)
    return ans

if __name__ == '__main__':
    T = int(input())
    ans = []
    for _ in range(T):
        ans.append(solve())

    for a in ans:
        print(a)