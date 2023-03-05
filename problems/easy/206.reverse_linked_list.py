"""  [Problem]
        - Given the head of a singly linked list, reverse the list, and return the reversed list.
*   [Idea]
        - Use extra variable to store the next node(forward).
        - point current.next to the previous node(prev).
        - set previous = current node.
        - set current node = forward(stored current.next).
        - iterate through all the nodes of the given linked list.
        
    [Complexity]
        - Time : O(n), where n= n nodes of linked list.
        - Space : O(1).
"""
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        """
        [1 -> 2 -> 3 -> None]
        (head)
        (curr)(forward)

        [None <- 1 <- 2 <- 3] 
        (prev)(curr)(forward)->
        i.e.,
        [3 -> 2 -> 1 -> None]
        """
        previous = None
        current = head

        while current:
            forward = current.next
            current.next = previous
            previous = current
            current = forward
            
            
        return previous