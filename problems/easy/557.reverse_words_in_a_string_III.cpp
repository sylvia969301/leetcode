#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
/*
"""  [Problem]
        - Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

    [Idea]
        - Use two pointers to iterate the given array
        - swap values each iteration until two pointers meet each other.

    [Complexity]
        - Time : O(N)
        - Space : O(n) change result in-place.
"""
*/

class Solution {
public:
    string reverseWords(string s) {
        // stringstream ss (s);
        // string t, ans;
        // while(getline(ss, t, ' ')){
        //     reverse(t.begin(), t.end());
        //     ans = ans + t + ' ';
        // }
        // return ans.substr(0, ans.size()-1);
        int i = 0;
        for(int j=1; j<=s.length(); j++){
            if(s[j]== ' ' || j==s.length()){
                reverse(s.begin()+i, s.begin()+j);
                i = j+1;
            }
        }
        return s;
    }
};