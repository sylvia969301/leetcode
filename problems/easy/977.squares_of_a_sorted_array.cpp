#include <vector>
#include <cstdlib>
using namespace std;
/*
"""  [Problem]
        - Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

    [Complexity]
        - Time : O(n).
        - Space : O(n), use extra space .
"""
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r=n-1, k=n-1;

        vector<int> result(n);
        
        while( l <= r){
            if(abs(nums[l]) > abs(nums[r])) {
                result[k] = nums[l]*nums[l];
                l +=1;
            }
            else {
                result[k] = nums[r]*nums[r];
                r -= 1;
            }
            k -=1;
        }
        return result;

    }
};