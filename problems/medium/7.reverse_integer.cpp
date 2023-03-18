#include <cstddef>
#include <limits.h>
using namespace std;
/*
"""  [Problem]
        - Given a signed 32-bit integer x, return x with its digits reversed.
        - If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
*   [Idea]
        - Use methematic solution to calculate the value of the reverse integer
    [Complexity]
        - Time : O(n), where n is the digits of the given number x.
        - Space : O(1).
"""
*/
class Solution {
public:
    int reverse(int x) {
        long accumulate = 0;
        while(x){
            accumulate = accumulate * 10 + x % 10;
            x /= 10;
        }
        if (accumulate  > INT_MAX || accumulate < INT_MIN) return 0;
        return int(accumulate);
    }
};