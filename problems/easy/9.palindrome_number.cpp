
using namespace std;
/*
    [Problem]
        - Given an integer x, return true if x is a 
          palindrome, and false otherwise.
*   [Idea]
        - Use arithmetic operations.
        - inverted input is calculated by %10 (last digit) & divided by 10 each time until =0.
        - return inverted == input
    [Complexity]
        - Time : O(n), where n=len(str(x))
        - Space : O(1).
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if( x <0 ) return false;

        int copyX = x;
        unsigned int invertedX = 0;
        while(copyX >0){
            invertedX = copyX %10 + invertedX*10;
            copyX /= 10;
        }
        return invertedX == x;
    }
};