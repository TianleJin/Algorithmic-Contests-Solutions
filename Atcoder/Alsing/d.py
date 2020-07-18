it = lambda: list(map(int, input().strip().split()))


def count(num):
    cnt = 0
    while num > 0:
        if num & 1:
            cnt += 1
        num = num >> 1
    return cnt

def find(num):
    ans = 0
    while num > 0:
        ans += 1
        cnt = count(num)
        num = num % cnt
    return ans

def create(N, cnt):
    cur = 1
    two = [0] * N
    for i in range(N):
        two[i] = cur % cnt
        cur = (cur << 1) % cnt
    return two

def getRem(N, A, cnt, two):
    rem = 0
    for i in range(N):
        if A[i] == '1':
            rem = (rem + two[N - i - 1]) % cnt
    return rem

def solve():
    N = int(input())
    A = list(input().strip())

    popcount = 0
    for i in range(N):
        if A[i] == '1':
            popcount += 1
    
    more = popcount + 1
    less = popcount - 1

    if less != 0:
        less_two = create(N, less)
        rem_less = getRem(N, A, less, less_two)
    more_two = create(N, more)
    rem_more = getRem(N, A, more, more_two)
    
    nums = []
    for i in range(N):
        if A[i] == '1':
            if less == 0:
                nums.append(-1)
            else:
                nums.append((rem_less - less_two[N - i - 1]) % less)
        else:
            nums.append((rem_more + more_two[N - i - 1]) % more)

    for num in nums:
        if num == -1:
            print(0)
        else:
            print(find(num) + 1)


solve()