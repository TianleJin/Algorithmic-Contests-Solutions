# cook your dish here
def solve(N, people):
    prev = -1
    for i in range(N):
        if people[i]:
            prev = i
            break
        
    if prev == -1:
        print("YES")
        return
    
    for i in range(prev + 1, N):
        if people[i]:
            if i - prev < 6:
                print("NO")
                return
            prev = i
            
    print("YES")
        
        
T = int(input())
for _ in range(T):
    N = int(input())
    people = list(map(int, input().strip().split()))
    solve(N, people)