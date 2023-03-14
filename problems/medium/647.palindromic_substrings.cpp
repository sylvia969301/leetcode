#include <string>
using namespace std;
/*
### Expand Around the Center
"""  [Problem]
        - Given a string s, return the number of palindromic substrings in it.
        - A string is a palindrome when it reads the same backward as forward.
        - A substring is a contiguous sequence of characters within the string.
*   [Idea]
        - Using 中心擴張法(Expand Around the Center), expand if s[left]==s[right].
        - Check 2 chars (even) and 3 chars(odd) that contains longest palindrome each time.
    [Complexity]
        - Time : O(n^2), where n is the size of the given array.
        - Space : O(1).
"""
*/

class Solution {
public:
    int countSubstrings(string s) {
        int oddPalindrome=0;
        int evenPalindrome = 0;
        for(int i=0; i<s.length() ; i++){
            oddPalindrome += expandOutward(s, i, i);
            evenPalindrome += expandOutward(s, i, i+1);
        }

        return oddPalindrome + evenPalindrome;

    }
    int expandOutward(string s, int left, int right){
        int count = 0;
        while(left >=0 && right < s.length() && s[left]==s[right]){
            left -=1;
            right +=1;
            count +=1;
        }
        return count;
    }
};