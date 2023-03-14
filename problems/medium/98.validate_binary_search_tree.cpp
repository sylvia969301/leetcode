#include <vector>
#include <limits>
using namespace std;
/*
"""  [Problem]
        - Given the root of a binary tree, determine if it is a valid binary search tree (BST).
          A valid BST is defined as follows:        
            - The left subtree of a node contains only nodes with keys less than the node's key.
            - The right subtree of a node contains only nodes with keys greater than the node's key.
            - Both the left and right subtrees must also be binary search trees.
    [Idea]
        - Use Depth Firt Search(DFS) to traverse the BST and push nodes into stack.
        - Since stack is LIFO(Last In First Out), compare previous node with the one poped from stack.
        - NOT valid if the value of root <= the previous node.
    [Complexity]
        - Time : O(n), where the given BST has n nodes.
        - Space : O(n), use extra space to implement stack mechanism.
"""
*/
/**
 * Definition for a binary tree node.*/
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    long int prevN = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (!root){
            return true;
        }

        
        bool ans = isValidBST(root->left);
        if(root->val <= prevN){
            return false;
        }else{
            prevN = root->val;
        }

        return ans && isValidBST(root->right);


        
    }
};