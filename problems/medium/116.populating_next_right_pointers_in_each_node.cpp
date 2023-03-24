#include <cstdlib>
using namespace std;
/*
"""  [Problem]
        - Populate each next pointer to point to its next right node. 
        - If there is no next right node, the next pointer should be set to NULL.
*   [Idea]
        - Use recursive method.
        - Start from the root, set root.left.next = root.right, if have root.right.
        - set root.right.next = root.next.left, if have root.next(cross the left and right subtrees)
    [Complexity]
        - Time : O(N), where N is the number of nodes of the given complete binary tree.
        - Space : O(1), since changing pointers of linked list( Not include the recursive calls in stack).
"""
*/

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {

        if(!root) return NULL;

        if(root->right) {
            root->left->next = root->right;
            if(root->next){
                root->right->next = root->next->left;
            }
        }
        connect(root->left);
        connect(root->right);
        return root;
        
    }
};