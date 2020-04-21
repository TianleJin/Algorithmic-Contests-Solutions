from collections import deque
def min_operations(n):
    steps = 0
    vis = set()
    queue = deque([1])
    while queue:
        steps += 1
        for _ in range(len(queue)):
            num = queue.popleft()
            a1, a2, a3 = num + 1, num * 2, num * 3
            if a1 == n or a2 == n or a3 == n:
                return steps
            if a1 not in vis:
                vis.add(a1)
                queue.append(a1)
            if a2 not in vis:
                vis.add(a2)
                queue.append(a2)
            if a3 not in vis:
                vis.add(a3)
                queue.append(a3)
    return steps
print(min_operations(10000000))