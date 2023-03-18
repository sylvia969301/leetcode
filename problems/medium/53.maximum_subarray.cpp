#include <vector>
using namespace std;

/*
"""  [Problem]
        - Given an integer array nums, find the subarray with the largest sum, 
           and return its sum.
*   [Idea]
        - Use Dynamic Programming(DP), 
          since the calculation of each state can be stored and reused.
    [Complexity]
        - Time : O(n), where n is the size of the given array nums.
        - Space : O(n).
"""
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp = {nums[0]};
        int maxNum = dp[0];
        int tmpMax;

        for(int i=1; i<nums.size(); i++){
            tmpMax = max(nums[i], nums[i] + dp[i-1]);
            dp.push_back(tmpMax);
            if(tmpMax >maxNum) maxNum = tmpMax;

        }
        return maxNum;
    }
};