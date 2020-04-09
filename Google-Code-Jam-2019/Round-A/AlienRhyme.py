# import sys
# sys.setrecursionlimit(2 ** 50) 


class Trie:
    def __init__(self):
        self.cnt = 0
        self.children = dict()


def solve(n, words):
    trie = Trie()

    for word in words:
        curr = trie
        for i in range(len(word) - 1, -1, -1):
            if word[i] not in curr.children:
                curr.children[word[i]] = Trie()
            curr = curr.children[word[i]]
        curr.cnt += 1

    ans = [0]

    def dfs(node):
        for ch in node.children.values():
            dfs(ch)
            node.cnt += ch.cnt
        
        if node is not trie and node.cnt >= 2:
            ans[0] += 2
            node.cnt -= 2

    dfs(trie)
    return ans[0]


if __name__ == '__main__':
    T = int(input())
    for t in range(1, T + 1):
        n = int(input())
        words = [input().strip() for _ in range(n)]
        ans = solve(n, words)
        print("Case #{}: {}".format(t, ans))