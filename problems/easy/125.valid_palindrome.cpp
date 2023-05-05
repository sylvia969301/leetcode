/*  [Problem]
        - Given a string s, return true if it is a palindrome, or false otherwise.
*   [Idea]
        - Use two pointers and a helper function isAlphaNum which checks ASCII by determine whether it's a alpha/number or not.
    [Complexity]
        - Time : O(N), where N is the length of the given array of prices.
        - Space : O(1), constant space.
*/

#include <string>
#include <ctype.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        
        int l = 0;
        int r = s.length()-1;
        while (l < r){
            while(l<r && !isalnum(s[l])) l+=1;
            while(r>l && !isalnum(s[r])) r-=1;
            if(tolower(s[l]) != tolower(s[r])) return false;
            
            l +=1;
            r -=1;
        }
        return true;
    }
};