#include <vector>
#include <unordered_map>
using namespace std;
/*
"""  [Problem]
        - Given an array of integers nums and an integer target, 
          return indices of the two numbers such that they add up to target.

    [Idea]
        - Use unordered map in C++ to get unique numbers in the given vector.
        - Find the map by complement, return indices if found, else insert values in the map.

    [Complexity]
        - Time : O(n), where n is the max size of the given string.
        - Space : O(n), use dictionary for extra space to store unique values.
"""
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> searchMap;
        for(int i = 0; i< nums.size(); i++){
            int diff = target - nums[i];
            if(searchMap.find(diff) != searchMap.end()){
                return {searchMap[diff], i};
            }
            searchMap[nums[i]] = i;
        }
        return {};
    }
};