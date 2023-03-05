
#include <cstddef>
/*  [Problem]
        - Given the root of a binary tree, invert the tree, and return its root.
*   [Idea]
        - Invert left sub-tree first, and then invert right sub-tree.
        - Finnally invert left child and right child.
    [Complexity]
        - Time : O(n), where n = #tree nodes.
        - Space : O(1).
*/
// Definition for a binary tree node.
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        invertTree(root->left);
        invertTree(root->right);
        TreeNode * tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        return root;
    }
};