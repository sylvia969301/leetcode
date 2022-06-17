#include <iostream>
#include <vector>

using namespace std;
/*
* [Problem] 
    - Merge two given binary trees. If two nodes overlap, then sum node values up as the new value of the merged node.
* [Idea]
    - Use the recursive way: calling mergeTrees function recursively.
    - Use Preorder traversal, i.e.,DFS(Depth-First Search) to traverse two given binary trees.
* [Complexity]
    - Time : O(m). Minimum number m of nodes from two given binary trees, total m*m nodes need to be traversed.
    - Space : 
        - Worst case is O(m), if skewed binary tree.
        - Average case is O(log m), since the depth of a complete/balanced binary tree which has m nodes is log(m).
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

class Solution{
public:
    TreeNode *mergeTrees(TreeNode* tree1, TreeNode* tree2){
        if (tree1==NULL) {
            return tree2;
        }else if (tree2==NULL){
            return tree1;
        }else{
            tree1->val += tree2->val;
            tree1->left  = mergeTrees(tree1->left, tree2->left);
            tree1->right = mergeTrees(tree1->right, tree2->right);
            return tree1;
        }
    }
};
