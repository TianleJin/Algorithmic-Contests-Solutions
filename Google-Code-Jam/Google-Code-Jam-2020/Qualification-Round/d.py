def reverse(state):
    i = 0 
    j = len(state) - 1
    while i < j and (state[i] != -1 or state[j] != -1):
        state[i], state[j] = state[j], state[i]
        i += 1
        j -= 1

def invert(state):
    n = len(state)
    i = 0 
    while i < n and state[i] != -1:
        state[i] = 1 - state[i]
        i += 1
    j = n - 1
    while j >= 0 and state[j] != -1:
        state[j] = 1 - state[j]
        j -= 1

def specialQuery(same, diff, state):
    if same == -1:
        # all different bits
        print(diff + 1, flush=True)
        if state[diff] != int(input()):
            reverse(state)
        print(diff + 1, flush=True)
        dummy = int(input())
    elif diff == -1:
        # all same bits
        print(same + 1, flush=True)
        if state[same] != int(input()):
            invert(state)
        print(same + 1, flush=True)
        dummy = int(input())
    else:
        # both different and same
        print(diff + 1, flush=True)
        if state[diff] != int(input()):
            # inverted or reversed
            print(same + 1, flush=True)
            if int(input()) != state[same]:
                # inverted
                invert(state)
            else:
                # reversed
                reverse(state)
        else:
            # nothing or both
            print(same + 1, flush=True)
            if int(input()) != state[same]:
                # both 
                invert(state)
                reverse(state)
    return 2

def solve(B):
    special = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150}
    state = [-1] * B
    same = diff = -1
    query = 0
    total = 0
    i = 0
    j = B - 1
    while i < j and query < 150 and total < B:
        if query in special:
            query += specialQuery(same, diff, state)

        print(i + 1, flush=True)
        state[i] = int(input())
        query += 1
        total += 1
        
        if total == B:
            return state

        if query in special:
            query += specialQuery(same, diff, state)

        print(j + 1, flush=True)
        state[j] = int(input())
        query += 1
        total += 1

        if state[i] != state[j]:
            diff = i
        else:
            same = i
        i += 1
        j -= 1
    return state

if __name__ == "__main__":
    T, B = input().strip().split()
    T, B = int(T), int(B)
    for _ in range(1, T + 1):
        ans = solve(B)
        print("".join(str(i) for i in ans), flush=True)
        if input().strip() == "N":
            break