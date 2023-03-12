#include <vector>
using namespace std;
/* [Problem]
        - Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
        - Return the running sum of nums.
*   [Idea]
        - Use for loop to iterate through all the elements of nums.
        - nums[i] += nums[i-1]
    [Complexity]
        - Time : O(n), where the length of given list is n.
        - Space : O(1).
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++){
            nums[i] += nums[i-1];
        }

        return nums;
    }
};