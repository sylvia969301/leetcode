#include <iostream>
using namespace std;

/*  [Problem] 
        - Given a binary tree, return its maximum tree depth.
*   [Idea]
        - Using preorder i.e.,DFS(Depth-First-Search)
*   [Complexity]
        - Time : O(n) for a binary tree which has n nodes, visited each node exacly once.
        - Space : 
            - Worst case  O(n), if skewed binary tree.
            - Best case O(log n), since the depth of a n nodes balanced/complete binary tree is log(n).
*/

struct TreeNode{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};

class Solution{
public:
    int maxDepth(TreeNode *root)  {

        if(!root){
            return 0;
        }
        int left_child_depth = maxDepth(root->left);
        int right_child_depth = maxDepth(root->right);
        int tree_depth = 1 + max(left_child_depth, right_child_depth);
        return tree_depth;
    }
};

int main(){
    int max_depth = 0;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    Solution s;
    max_depth = s.maxDepth(root);
    cout<< "Tree Depth = " << max_depth << endl;
    return 0;
}