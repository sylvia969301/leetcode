"""  [Problem]
        - Given the head of a singly linked list, return the middle node of the linked list.
        - If there are two middle nodes, return the second middle node.
*   [Idea]
        - Use two pointers (slow one and fast one) to traverse the given linked list.
        - slow one = next node while fast one = next two nodes
        - it will find thr middle of the linked list once tha fast one reach the tail of the given linked list.
    [Complexity]
        - Time : O(n), where n is the number of given nodes of the linked list.
        - Space : O(1).
"""

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        slow , fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow