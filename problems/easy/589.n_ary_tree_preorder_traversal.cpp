#include <vector>
#include <stack>
using namespace std;
/*
    [Problem]
        - Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
          Preorder traversal means : ROOT -> LEFT CHILD -> RIGHT CHILD .
          ( Inorder : LEFT -> ROOT -> RIGHT, 
            Postorder : LEFT -> RIGHT -> ROOT )

*   [Idea]
        - Use Stack (implement by Stack pop(), push() in C++) to store nodes of the given n-ary tree.
        - Use stack.front() to get the top node and pop() the node from stack (Last In First Out manner),
          push children nodes of the current node into the stack in reversed order. (Since pre-order traversal)
        
    [Complexity]
        - Time : O(N), where N is the number of nodes in the given n-ary tree.
        - Space : O(N), use stack (implemented by Stack in C++) for extra space.
*/

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> stack_;
        vector<int> result;
        if(!root) return result;
        stack_.push(root);

        while(!stack_.empty()){
            Node* curr = stack_.top();
            stack_.pop();
            result.push_back(curr->val);

            int childrenNum = curr->children.size();
            while(childrenNum -- ){
                stack_.push(curr->children[childrenNum]);
            }
        }
        return result;
    }
};