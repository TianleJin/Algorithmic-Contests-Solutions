from collections import deque, defaultdict
it = lambda: list(map(int, input().strip().split()))


def solve():
    n, m = it()
    ans = set()
    indegree = defaultdict(int)
    decided = defaultdict(list)
    undecided = defaultdict(list)
    queue = deque()
    for _ in range(m):
        a, x, y = it()
        if a == 1:
            indegree[y] += 1
            decided[x].append(y)
        else:
            undecided[x].append(y)
            undecided[y].append(x)

    for x in range(1, n + 1):
        if indegree[x] == 0:
            queue.append(x)

    while queue and len(ans) < m:
        x = queue.popleft()
        for y in decided[x]:
            ans.add((x, y))
            indegree[y] -= 1
            if indegree[y] == 0:
                queue.append(y)
        for y in undecided[x]:
            if not (x, y) in ans and not (y, x) in ans:
                ans.add((x, y))
    
    if len(ans) < m:
        print('NO')
    else:
        print('YES')
        for x, y in ans:
            print(x, y)


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solve()