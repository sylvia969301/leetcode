
/*

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
*/

/**
 * Definition for singly-linked list.
 *  */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast= head;
        ListNode* slow = head;
        for(int i=0; i<n ; i++) fast = fast->next;

        if( !fast) return head->next;

        while(fast->next) fast = fast->next, slow = slow->next;

        slow->next = slow->next->next;
        return head;
    }
};