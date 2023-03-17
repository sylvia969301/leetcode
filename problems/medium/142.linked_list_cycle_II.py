
"""  [Problem]
        - Given head, the head of a linked list, determine if the linked list has a cycle in it.

    [Idea]
        - Use Floyd's Cycle-Finding algorithm to detect a cycle in a linked list.
        - Use two nodes (faster one and slower one) to compare with each other.
        - faster one = next two node, slower one = next node each iteration
        - if two pointers meet, there is a cycle in the linked list.
        - reset the slower one to head, move both pointers until they meet again.(meet at the starting point of the cycle)

    [Complexity]
        - Time : O(N)
        - Space : O(1).
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            # If the pointers meet, there is a cycle in the linked list.
            # Reset the slow pointer to the head of the linked list, and move both pointers one step at a time
            # until they meet again. The node where they meet is the starting point of the cycle.
            if slow == fast:
                slow = head
                while slow != fast:
                    slow = slow.next
                    fast = fast.next
                return slow
        return None