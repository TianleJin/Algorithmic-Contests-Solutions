from collections import deque
it = lambda: list(map(int, input().strip().split()))


def case():
    print(39 * 39)
    for i in range(2, 41):
        for j in range(2, 41):
            print(i, j)


def brute():
    R, S = it()
    N = R * S
    A = [0] * N
    for i in range(N):
        A[i] = i % R
    
    E = sorted(A)
    vis = set()
    vis.add(tuple(A))
    queue = deque()
    queue.append((0, A))
    while queue:
        moves, state = queue.popleft()
        if state == E:
            return moves
        for i in range(N):
            for j in range(i + 1, N):
                new_state = state[i+1:j+1] + state[:i+1] + state[j+1:]
                if not tuple(new_state) in vis:
                    vis.add(tuple(new_state))
                    queue.append((moves + 1, new_state))


def check(N, R, S, moves):
    A = [0] * N
    for i in range(N):
        A[i] = i % R

    for x, y in moves:
        A = A[x:x+y] + A[:x] + A[x+y:]
    
    for i in range(N):
        assert A[i] == i // S


def solve(tt):
    R, S = it()
    N = R * S

    A = [0] * N
    C = [1] * N
    for i in range(N):
        A[i] = i % R

    queue = deque(A)
    count = deque(C)

    total = 0
    moves = []
    while len(queue) > R:
        total += 1
        r1, r2 = queue.popleft(), queue.popleft()
        c1, c2 = count.popleft(), count.popleft()

        c3 = 0
        for i in range(len(queue)):
            c3 += count[i]
            if queue[i] == r1:
                break
        assert queue[i] == r1

        if i + 1 == len(queue):
            assert len(queue) < R and r1 + 1 == R
            count[i] += c1
            queue.appendleft(r2)
            count.appendleft(c2)
            moves.append([c1, c2 + c3])
        else:
            assert queue[i + 1] == r2
            count[i] += c1
            count[i + 1] += c2
            moves.append([c1 + c2, c3])

    # check(N, R, S, moves)
    print("Case #{}: {}".format(tt, total))
    for x, y in moves:
        print(x, y)


if __name__ == '__main__':
    T = int(input())
    for tt in range(1, T + 1):
        solve(tt)
    
    # case()