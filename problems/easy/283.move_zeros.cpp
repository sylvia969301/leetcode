#include <vector>
using namespace std;
/*
"""  [Problem]
        - Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    [Idea]
        - Use i to keep track of position of the first zero in the list (which changes as we go).
        - usejto keep track of the first non-zero value after the first zero (which is pointed by i).
        - Each time we have i correctly points to a zero and j correctly points to the first non-zero after i, we swap the values that store at i and j.

    [Complexity]
        - Time : O(N)
        - Space : O(1) change result in-place.
"""
*/
class Solution{
    public:
    void moveZeroes(vector<int>& nums){
        int zeroIdx = 0;
        int n = nums.size();
        for(int i =0; i< n; i++){
            if(nums[i]!=0){
                int dummy = nums[i];
                nums[i] = nums[zeroIdx];
                nums[zeroIdx] = dummy;
                zeroIdx +=1;
                
            }

        }
    }
};