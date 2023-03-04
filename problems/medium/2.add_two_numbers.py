
"""  [Problem]
        - Given 2 non-empty linked list contain non-negative integer.
        - Digits are store in reverse order. Each code contains a single digit.
        - Add two numbers and return the sum as a linked list.
*   [Idea]
        - Difine singly-linked list
        - carry is calculated by // 10.
        - next node of number is calculated by % 10.
    [Complexity]
        - Time : O(max(m, n)), where len(l1)=m, len(l2)=n.
        - Space : O(max(m, n)).
"""

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

        carry = 0
        result = ListNode(0)
        pointer = result

        while l1 or l2 or carry:
            firstNum = l1.val if l1 else 0
            secondNum = l2.val if l2 else 0

            sum = firstNum + secondNum + carry
            num = sum % 10
            carry = sum // 10

            pointer.next = ListNode(num)
            pointer = pointer.next

            l1 = l1.next if l1.next else None
            l2 = l2.next if l2.next else None
        
        return result.next

