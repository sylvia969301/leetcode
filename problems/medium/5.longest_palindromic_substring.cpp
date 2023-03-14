#include <vector>
#include <string>
using namespace std;

/*
### Expand Around the Center
"""  [Problem]
        - Given a string s, return the longest palindromic substring in s.
*   [Idea]
        - Using 中心擴張法(Expand Around the Center), expand if s[left]==s[right].
        - Check 2 chars (even) and 3 chars(odd) that contains longest palindrome each time.
    [Complexity]
        - Time : O(n^2), where n is the size of the given array.
        - Space : O(1), no need to maintain the DP table.
"""
*/

class Solution {
public:
    vector<int> expandAroundTheCenter(string s, int left, int right){
        while(left >=0 && right <s.length() && s[left]==s[right]){
            left -= 1;
            right +=1;
        }
        
        return {left+1, right};
    }
    string longestPalindrome(string s) {
        vector<int> longestPalindrome = {0, 1};
        for(int i=1; i<s.length(); i++){
            vector<int> oddPalindrome = expandAroundTheCenter(s, i-1, i+1);
            vector<int> evenPalindrome = expandAroundTheCenter(s, i-1, i);

            if(oddPalindrome[1]-oddPalindrome[0] < evenPalindrome[1]-evenPalindrome[0]){
                if(longestPalindrome[1] - longestPalindrome[0] < evenPalindrome[1]-evenPalindrome[0]){
                    longestPalindrome = {evenPalindrome[0], evenPalindrome[1]};
                }
            }else{
                if(longestPalindrome[1] - longestPalindrome[0] < oddPalindrome[1]-oddPalindrome[0]){
                    longestPalindrome = {oddPalindrome[0], oddPalindrome[1]};
                }
            }
            
        }
        
        return s.substr(longestPalindrome[0], (longestPalindrome[1]-longestPalindrome[0]));
    }
};