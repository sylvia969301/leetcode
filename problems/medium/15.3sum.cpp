#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/*
"""  [Problem]
        - Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
        - Notice that the solution set must not contain duplicate triplets.
*   [Idea]
        - Sort the input first. O(NlogN)
        - Summing up three pointers, insert into the set if sum=0 else left++, right--. O(n^2)

    [Complexity]
        - Time : O(N^2), bounded by the nested loop checking summation of three pointers.
        - Space : O(N), output can up to input size.
"""
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> out;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int left, right;
        vector<int> trip;
        

        for(int i =0; i<nums.size(); i++){
            left = i+1;
            right = nums.size()-1;
            if(nums[i] >0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;
            
            while(left < right){
                if(nums[i] + nums[left] + nums[right] ==0){
                    trip = {nums[i], nums[left], nums[right]};
                    out.insert(trip);
                    left +=1;
                    right -=1;
                }else if (nums[i] + nums[left] + nums[right] < 0){
                    left +=1;
                }else{
                    right -=1;
                }
            }
            
        }
        for(auto comb: out) ans.push_back(comb);
        return ans;
    }
};