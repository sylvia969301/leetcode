#include <cstddef>
using namespace std;
/*
    [Problem]
        - Given the head of a singly linked list, reverse the list, and return the reversed list.
*   [Idea]
        - Use extra variable to store the next node(forward).
        - point current.next to the previous node(prev).
        - set previous = current node.
        - set current node = forward(stored current.next).
        - iterate through all the nodes of the given linked list.
        
        example:
        [1 -> 2 -> 3 -> None]
        (head)
        (curr)(forward)

        [None <- 1 <- 2 <- 3] 
        (prev)(curr)(forward)->
        i.e.,
        [3 -> 2 -> 1 -> None]
        
    [Complexity]
        - Time : O(n), where n= n nodes of linked list.
        - Space : O(1).
*/

//  * Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;

        }
        return prev;
    }
};