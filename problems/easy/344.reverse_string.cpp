#include <vector>
using namespace std;
/*
"""  [Problem]
        - Write a function that reverses a string. The input string is given as an array of characters s.

    [Idea]
        - Use two pointers to iterate the given array
        - swap values each iteration until two pointers meet each other.

    [Complexity]
        - Time : O(N)
        - Space : O(1) change result in-place.
"""
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            char dummy = s[left];
            s[left] = s[right];
            s[right] = dummy;
            left +=1;
            right -=1;
        }
    }
};