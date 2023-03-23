
/*
"""  [Problem]
        - You are given two binary trees root1 and root2.
        - Imagine that when you put one of them to cover the other, 
          some nodes of the two trees are overlapped while the others are not. 
          You need to merge the two trees into a new binary tree. 
        - The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node.
          Otherwise, the NOT null node will be used as the node of the new tree.
*   [Idea]
        - Use DFS (Depth First Search) begin from root of two binary trees, merge left-subtrees first, then merge right-subtrees recursively.
        - If nodes overlap, sum node values up as the new value.
    [Complexity]
        - Time :  O(m), a total of m nodes need to be traversed, where m is the minimum nodes of two given binary trees.
        - Space : O(m) in worst case , the depth of recursions can go upto m in case of skewed binary tree. In average case, it would be O(log m) from the tree height.
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 && root2){
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
        }else{
            return root1 ? root1 : root2;
        }
        return root1;
    }
};