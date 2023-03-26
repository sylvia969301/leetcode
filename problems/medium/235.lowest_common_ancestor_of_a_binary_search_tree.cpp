#include <cstddef>
using namespace std;
/*
"""  [Problem]
        - Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
        - According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

    [Idea]
        - Set root as current node, compare p and q node each time.
        - Continuing compare with right sub-tree (curr = curr.right), if p and q both greater than curr.
        - Continuing compare with left sub-tree (curr = curr.left), if p and q both less than curr.

    [Complexity]
        - Time : O(log n), where n is the number of nodes of the given BST, and its tree height = logn.
        - Space : O(1), constant space.
"""
*/
/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* curr = root;
        while(true){
            if(p->val > curr->val && q->val > curr->val){
                curr = curr->right;
            } 
            else if(p->val < curr->val && q->val < curr->val) {
                curr = curr->left;
            }
            else {
                break;
            }
        }
        return curr;
    }
};