def solve():
    command = input().strip()
    memo = {'N':(-1, 0), 'S':(1, 0), 'E': (0, 1), 'W':(0, -1)}
    def dfs(command):
        move = [0, 0]
        n = len(command)
        i = 0
        while i < n:
            ch = command[i]
            if ch.isdigit():
                k = i
                while i < n and command[i].isdigit():
                    i += 1
                multiplier = int(command[k:i])
                i -= 1
                open = 0
                for j in range(i + 1, n):
                    ch1 = command[j]
                    if ch1 == '(' or ch1 == ')':
                        open += 1 if ch1 == '(' else -1
                        if open == 0:
                            x, y = dfs(command[i + 2:j])
                            move[0] += multiplier * x
                            move[1] += multiplier * y
                            i = j + 1
                            break
            else:
                x, y = memo[ch]
                move[0] += x
                move[1] += y
                i += 1
        return move
    move = dfs(command)
    move[0] %= (10 ** 9)
    move[1] %= (10 ** 9)
    move[0] += 1
    move[1] += 1
    return move


if __name__ == "__main__":
    T = int(input())
    for t in range(1, T + 1):
        move = solve()
        print('Case #{}: {} {}'.format(t, move[1], move[0]))
