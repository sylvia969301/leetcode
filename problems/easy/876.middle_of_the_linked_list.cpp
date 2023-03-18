

/*
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
*/
/**
 * Definition for singly-linked list.
 * */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        
    }
};