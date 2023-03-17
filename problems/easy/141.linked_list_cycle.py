"""  [Problem]
        - Given head, the head of a linked list, determine if the linked list has a cycle in it.

    [Idea]
        - Use two nodes (faster one and slower one) to compare with each other.
        - faster one = next two node, slower one = next node each iteration

    [Complexity]
        - Time : O(N)
        - Space : O(1).
"""

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        slow, fast = head, head
        while fast!=None and fast.next !=None:
            slow = slow.next
            fast = fast.next.next
            if fast == slow : return True

        return False