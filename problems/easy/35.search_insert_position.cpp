#include <vector>
using namespace std;
/*
"""  [Problem]
        - Given a sorted array of distinct integers and a target value,
          return the index if the target is found. If not, 
          return the index where it would be if it were inserted in order.
    
    [Idea]
        - Use Binary Search method , solve the problem by moving left and right pointers.

    [Complexity]
        - Time : O(log n), where n is the number of elements of the given array.
        - Space : O(1).
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1;

        while(left <= right){
            int mid = (left+right) / 2;
            if(nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid +1;
            else right = mid -1;
        }
        return left;
    }
};