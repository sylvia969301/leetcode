#include <unordered_map>
#include <vector>
using namespace std;
/*
"""  [Problem]
        - Given an integer array nums, 
          return true if any value appears at least twice in the array, 
          and return false if every element is distinct.

    [Idea]
        - Use unordered map in C++ to get unique values in the given array.
          which has average time of O(1) in insertion and serching.

    [Complexity]
        - Time : O(n), where n is the size of the given array.
        - Space : O(n), use unordered map for extra space to store unique values.
"""
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map <int, int> map;
        
        for(auto n : nums){
            if( ++map[n] > 1) return true;
        }
        return false;
    }
};