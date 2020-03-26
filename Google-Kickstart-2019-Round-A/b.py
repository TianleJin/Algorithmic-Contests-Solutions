def parse():
    n, k = input().strip().split()
    n, k = int(n), int(k)
    skills = [int(i) for i in input().strip().split()]
    return n, k, skills

def solve(n, k, skills):
    skills.sort()
    
    presum = [0] * (n + 1)
    for i in range(1, n + 1):
        presum[i] = presum[i - 1] + skills[i - 1]
    
    ans = float('inf')
    for i in range(k - 1, n):
        ans = min(ans, skills[i] * k - (presum[i + 1] - presum[i - k + 1]))
    return ans

if __name__ == "__main__":
    n = int(input())
    for i in range(1, n + 1):
        n, k, skills = parse()
        ans = solve(n, k, skills)
        print("Case #{}: {}".format(i, ans))
