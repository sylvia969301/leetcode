#include <iostream>
#include <vector>
using namespace std;

/*  [Problem]
        - Given a integer array nums, 
          return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
        - The algorithm must run in O(n) time and without using division operation.
*   [Idea]
        - Use one extra array and one variable.
        - Set up the extra array index i=0 equals to integer 1.
        - Start with i=1 accendingly up to n, multiply extra array[i] by given nums[i-1]. 
        - Set up the extra variable equals to integer 1.
        - Further start with i=n-1 descendingly down to 0, multiply extra variable by extra array[i].
        - Return extra array as the answer.
    [Complexity]
        - Time : O(n)
        - Space : O(n). BUT!! May have a solution improve from O(n) to O(1), consider a extra variable only. Will update this solution soon.
*/

class Solution{
public:
    vector<int> productExceptSelf(vector<int> &nums){
        int n = nums.size();
        vector<int> answer(n);
        answer[0] = 1;

        for(int i=1; i<n ; i++){
            answer[i] = nums[i-1] * answer[i-1];
        }

        int reverse_product = 1;
        for(int i=n-1; i>=0; i--){
            answer[i] = answer[i] * reverse_product;
            reverse_product = reverse_product * nums[i];
        }
        return answer;
    }
};

int main(){
    vector<int> nums{1, 2, 3, 4};
    Solution solution;
    vector<int> ans = solution.productExceptSelf(nums);
    for(auto num: ans){
        cout << "  " << num; //Should return 24  12  8  6
    }
    cout << endl;
    return 0;
}

