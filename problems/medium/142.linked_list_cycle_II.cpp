#include <cstddef>
using namespace std;
/*
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
*/

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                    
                }
                return slow;
            }
        }
        return NULL;
    }
};