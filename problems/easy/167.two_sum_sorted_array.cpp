#include <vector>
using namespace std;

/*
"""  [Problem]
        - Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
        find two numbers such that they add up to a specific target number. 
        Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

    [Idea]
        - Use two pointer(left and right), sum up two vlaue of they point to, 
        - left += 1, if target less than summation.
        - right -=1, if target greater than summation.

    [Complexity]
        - Time : O(N)
        - Space : O(1) change result in-place.
"""
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        vector<int> res;

        while(left < right){
            if((numbers[left] + numbers[right]) == target){
                
                res.push_back(left+1);
                res.push_back(right+1);
                break;
            }
            if(numbers[left] + numbers[right] < target) left += 1;
            else right -=1;
        }
        return res;
    }
};