
direction = {
    'N':(1, 0), 
    'E':(0, 1), 
    'S':(-1, 0), 
    'W':(0, -1)
}


def solve():
    Y, X, s = input().strip().split()
    Y, X = int(Y), int(X) 

    time = 0
    for move in s:
        dx, dy = direction[move]
        time += 1
        X += dx
        Y += dy
        if abs(X) + abs(Y) <= time:
            return time
    return -1


if __name__ == '__main__':
    T = int(input())
    for t in range(1, T + 1):
        time = solve()
        if time == -1:
            print('Case #{}: IMPOSSIBLE'.format(t))
        else:
            print('Case #{}: {}'.format(t, time))