#include <vector>
using namespace std;
/*
"""  [Problem]
        - Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n),
          ans[i] is the number of 1's in the binary representation of i.
*   [Idea]
        - DFS : 
            - preorder : root -> left -> right
            - inorder : left -> root -> right  
            - postorder : left -> right -> roots

        - Use recurssion method
        - combine left sub tree + root + right sub tree
    [Complexity]
        - Time : O(n), where n is the number of nodes of the given binary tree.
        - Space : O(n).
"""
*/


/**
 * Definition for a binary tree node.
 * */
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

    vector<int> ordered;
    vector<int> inorderTraversal(TreeNode* root) {

        if (root != nullptr){
            traverse(root);
            return ordered;
        }else{
            return ordered;
        }
        
    }
    void traverse(TreeNode* root){
            inorderTraversal(root->left);
            ordered.push_back(root->val);
            inorderTraversal(root->right);
    }
};