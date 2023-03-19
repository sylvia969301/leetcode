
"""  [Problem]
        - Given the head of a linked list,
          remove the nth node from the end of the list and return its head.
*   [Idea]
        - Use two pointers(fast and slow one)
        - stagger(錯開) two pointers by n nodes by giving the fast pointer a head start first.
        - let slow one to reach the n'th node from the end(which need to be removed) 
          at the same time that the fast one reaches the end.
    [Complexity]
        - Time : O(n), where n is the size of the given linked list.
        - Space : O(1).
"""

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        fast, slow = head, head
        for _ in range(n): fast = fast.next

        if not fast : return head.next

        while fast.next : 
            fast, slow = fast.next, slow.next

        slow.next = slow.next.next # remove the nth node from the linked list
        return head