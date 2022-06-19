#include <iostream>
#include <vector>
using namespace std;

/*  [Problem] Given an sorted array in an ascending order, return a height-balanced BST and print all of the nodes by preorder(DFS).
*   [Idea]
        - Recursively call the 'BST' function : cutting the array into two subarrays by the middel node, further construct two BSTs repectively.
        - While doing things mentioned above, always keep the height of BST balanced:
            - Let L = left boundary of an array ; Let R = right boundary of an array.
            - If L > R : return nullptr, since it's a wrong range.
            - If L <= R : find the middle node of the array/subarray by calculating middle = 'L + (R-L)/2'.
                return a new node which value equals to input_array[middle].
            - 
    [Complexity]
        - Time : O(n) as traversed all of the nodes in the given array which has n elements.
        
*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
};

class Solution {
public:
    void preorder(TreeNode* head)
    {
        if(!head)
            return;
        cout << head->val << " ";
        preorder(head->left);
        preorder(head->right);
    }
    TreeNode *BST(vector<int> &nums, int L, int R){
        if (L <= R){
            int middle = L + (R-L)/2;
            TreeNode *child_head = new TreeNode(nums[middle]);
            child_head->left = BST(nums, L, middle-1);
            child_head->right = BST(nums, middle+1, R);
            return child_head;
        }
        return nullptr;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums){
        TreeNode *answer_BST = BST(nums, 0, nums.size()-1);
        return answer_BST;

    }
};

int main (){
    vector<int> input_nums = {-10, -3, 0, 5, 9};
    Solution s;
    TreeNode *BST_root = s.sortedArrayToBST(input_nums);
    s.preorder(BST_root);
    cout << endl;
    return 0;
}


