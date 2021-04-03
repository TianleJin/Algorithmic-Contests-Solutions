from collections import defaultdict as ddt 
from collections import deque
from random import randint


istr = lambda: input().strip()
istrl = lambda: input().strip().split()
iint = lambda: int(input())
iintl = lambda: list(map(int, input().strip().split()))


class ListNode:
    def __init__(self, val, r, c):
        self.r = r
        self.c = c
        self.val = val
        self.prev = None
        self.next = None


def solve(R, C, dancers):
    ans = 0
    total = 0
    row_refs = {}
    col_refs = {}
    queue = deque()
    vis = set()

    for r in range(R):
        for c in range(C):
            total += dancers[r][c]

    for r in range(R):
        for c in range(C):
            queue.append((r, c))

    for r in range(R):
        val = dancers[r][0]
        head = ListNode(val, r, 0)
        row_refs[r, 0] = head
        for c in range(1, C):
            val = dancers[r][c]
            nxt = ListNode(val, r, c)
            head.next, nxt.prev = nxt, head
            row_refs[r, c] = nxt
            head = head.next

    for c in range(C):
        val = dancers[0][c]
        head = ListNode(val, 0, c)
        col_refs[0, c] = head
        for r in range(1, R):
            val = dancers[r][c]
            nxt = ListNode(val, r, c)
            head.next, nxt.prev = nxt, head
            col_refs[r, c] = nxt
            head = head.next
    
    for _ in range(R * C):
        if not queue:
            break

        ans += total
        eliminate = set()

        for _ in range(len(queue)):
            r, c = queue.popleft()
            row_ref = row_refs[r, c]
            col_ref = col_refs[r, c]
            neigh_sum = 0
            cnt = 0
            for neigh in (row_ref.prev, row_ref.next, col_ref.prev, col_ref.next):
                if neigh is not None:
                    neigh_sum += neigh.val
                    cnt += 1

            if cnt * row_ref.val < neigh_sum:
                eliminate.add((r, c))
            
        for r, c in eliminate:
            vis.add((r, c))
            row_ref = row_refs[r, c]
            col_ref = col_refs[r, c]
            total -= row_ref.val

            if row_ref.prev:
                row_ref.prev.next = row_ref.next
                coord = (row_ref.prev.r, row_ref.prev.c)
                if coord not in vis and coord not in eliminate:
                    queue.append(coord)

            if row_ref.next:
                row_ref.next.prev = row_ref.prev
                coord = (row_ref.next.r, row_ref.next.c)
                if coord not in vis and coord not in eliminate:
                    queue.append(coord)

            if col_ref.prev:
                col_ref.prev.next = col_ref.next
                coord = (col_ref.prev.r, col_ref.prev.c) 
                if coord not in vis and coord not in eliminate:
                    queue.append(coord)

            if col_ref.next:
                col_ref.next.prev = col_ref.prev
                coord = (col_ref.next.r, col_ref.next.c)
                if coord not in vis and coord not in eliminate:
                    queue.append(coord)
    return ans


if __name__ == "__main__":
    T = int(input())
    for t in range(1, T + 1):
        R, C = iintl()
        ans = solve(R, C, [iintl() for _ in range(R)])
        print("Case #{}: {}".format(t, ans))