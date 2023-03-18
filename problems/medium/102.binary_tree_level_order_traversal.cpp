#include <vector>
#include <queue>

using namespace std;
/*
"""  [Problem]
        - Given the root of a binary tree, return the level order traversal of its nodes' values. 
        (i.e., from left to right, level by level).
*   [Idea]
        - Use queue that pushes every nodes in the same level.
        - Queue.front() to take the first node from queue and Queue.pop() to remove from head.
        - append to result list every layer.
    [Complexity]
        - Time : O(n), where n is the number of given nodes of the binary tree.
        - Space : O(n), store level-order result in a list.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        TreeNode* node;
        vector<int> layer;

        while(!q.empty()){
            
            int n = q.size();
            while(n--){
                node = q.front();
                q.pop();
                layer.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            }
            res.push_back(layer);
            layer.clear();
        }
        return res;
    }
};