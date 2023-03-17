#include <cstddef>
using namespace std;
/**
 * """  [Problem]
        - Given head, the head of a linked list, determine if the linked list has a cycle in it.

    [Idea]
        - Use two nodes (faster one and slower one) to compare with each other.
        - faster one = next two node, slower one = next node each iteration

    [Complexity]
        - Time : O(N)
        - Space : O(1).
"""
 */
//* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head== NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) return true;
        }
        return false;
    }
};