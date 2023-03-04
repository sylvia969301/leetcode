#include <stddef.h>
using namespace std;
/*  [Problem]
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
*/

/* Definition for singly-linked list. */
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next){}

};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode *l2){
        ListNode* result = new ListNode();
        ListNode* pointer = result;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry){
            int sum = 0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            ListNode * nextNode = new ListNode(sum%10);
            pointer->next = nextNode;
            pointer = pointer->next;
        } 
        return result->next;
    }


};