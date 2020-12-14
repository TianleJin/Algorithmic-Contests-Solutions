from sys import setrecursionlimit as srl
srl(2 * 10 ** 6)

class Node:
    def __init__(self):
        self.cnt = 0
        self.children = {}

def parse():
    N, K = input().strip().split()
    N, K = int(N), int(K)
    strings = [input().strip() for _ in range(N)]
    return N, K, strings

def solve(N, K, strings):
    root = Node()
    for s in strings:
        curr = root
        for ch in s:
            if ch not in curr.children:
                curr.children[ch] = Node()
            curr = curr.children[ch]
        curr.cnt += 1
    
    def dfs(root, depth=0):
        ans = 0
        if root.children:
            for ch in root.children:
                child = root.children[ch]
                ans += dfs(child, depth + 1)
                root.cnt += child.cnt
            
        while root.cnt >= K:
            root.cnt -= K
            ans += depth
        return ans

    return dfs(root)
   
# Number of test cases
T = int(input())
for t in range(1, T + 1):
    N, K, strings = parse()
    ans = solve(N, K, strings)
    print("Case #{}: {}".format(t, ans))