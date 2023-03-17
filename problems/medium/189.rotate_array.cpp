#include <vector>
using namespace std;
/*

"""  [Problem]
        - Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

    [Complexity]
        - Time : O(n).
        - Space : O(1), use extra space .
"""
*/

class Solution {
public:
    void reverse(vector<int> & nums, int start, int end){
        while(start < end){
            int dummy = nums[start];
            nums[start] = nums[end];
            nums[end] = dummy;
            start +=1;
            end -=1;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k <0) k += nums.size();

        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
};