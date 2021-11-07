# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head):
        critical = []
        i = 0
        f = s = None
        while head:
            if f and s and (s.val > max(f.val, head.val) or s.val < min(f.val, head.val)):
                critical.append(i)
            f, s, head = s, head, head.next
            i += 1
        
        if len(critical) <= 1:
            return [-1, -1]
        
        return [
            min(critical[i + 1] - critical[i] for i in range(len(critical) - 1)),
            critical[-1] - critical[0]
        ]
