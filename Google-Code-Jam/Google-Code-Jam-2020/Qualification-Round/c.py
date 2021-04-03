def solve(N, act, t):
    act = [(s, e, idx) for idx, (s, e) in enumerate(act)]
    act.sort()
    schedule = [""] * N
    end = []
    for s, e, idx in act:
        if not end:
            end.append([e, 'C'])
            schedule[idx] = 'C'
        else:
            if s >= end[0][0]:
                end[0][0] = e
                schedule[idx] = end[0][1]
            else:
                if len(end) == 2:
                    print("Case #{}: IMPOSSIBLE".format(t))
                    return
                else:
                    free = 'C' if end[0][1] == 'J' else 'J'
                    end.append([e, free])
                    schedule[idx] = free
        end.sort()
    print("Case #{}: {}".format(t, ''.join(schedule)))


if __name__ == "__main__":
    T = int(input())
    for t in range(1, T + 1):
        N = int(input())
        act = []
        for _ in range(N):
            s, e = input().strip().split()
            act.append((int(s), int(e)))
        solve(N, act, t)
