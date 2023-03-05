#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

/*  [Problem]
        - Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
        - Return the sum of the three integers.
*   [Idea]
        - let the given list be sorted.
        - total = curret value + left pointer + right pointer
        - make sure the gap between target and total is minimized.
        - move the pointer of left and right untill they meet each other.
    [Complexity]
        - Time : O(n^2), where len(nums) = n.
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int closestSum = INT_MAX;
        sort(nums.begin(), nums.end());

        for (int i=0; i< nums.size()-2; i++){
            int left = i+1;
            int right = nums.size()-1;
            while(left < right ){
                int total = nums[i] + nums[left] + nums[right];
                if(total == target){
                    return total;
                }
                int diff = abs(total - target);
                if(closestSum == INT_MAX || diff < abs(closestSum - target)){
                    closestSum = total;
                }
                if(total < target){
                    left +=1;
                }else{
                    right -=1;
                }
                
            }
        }
        return closestSum;
    }
};