"""  [Problem]
        - You are given the heads of two sorted linked lists list1 and list2.
        - Merge the two lists in a one sorted list. 
          The list should be made by splicing together the nodes of the first two lists.
    
    [Idea]
        - Create a dummy node and a pointer that point to it first,
        - compare value of list 1 and 2, set pointer.next to l1 if l1.val < l2.val
        - traverse min(l1, l2) times, point to the last part of the longest list  

    [Complexity]
        - Time : O(n), where n is min(len(list1), len(list2)).
        - Space : O(n), use extra space to create LinkedList.
"""

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if list1 is None: return list2
        if list2 is None: return list1

        dummy = ListNode()
        pointer = dummy

        while list1 and list2:
            if list1.val < list2.val:
                pointer.next = list1
                list1 = list1.next
            else:
                pointer.next = list2
                list2 = list2.next

            pointer = pointer.next
            if list1: pointer.next = list1
            else: pointer.next = list2

        return dummy.next
