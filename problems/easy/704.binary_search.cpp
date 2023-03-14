#include <vector>
using namespace std;

/*
"""  [Problem]
        - Given an array of integers nums which is sorted in ascending order, 
            and an integer target, write a function to search target in nums. 
            If target exists, then return its index. Otherwise, return -1.

    [Complexity]
        - Time : O(log n), where n is the number of elements of the given array.
        - Space : O(1).
"""
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1 ;

        while(left <= right){
            int mid = (left + right ) / 2 ;
            if (nums[mid] == target) return mid;
            else if(target > nums [mid]) left = mid +1;
            else right = mid - 1;
        }
        return -1;
    }
};