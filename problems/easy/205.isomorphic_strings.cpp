#include <string>
using namespace std;
/*
"""  [Problem]
        - Given two strings s and t, determine if they are isomorphic.
        - Two strings s and t are isomorphic if the characters in s can be replaced to get t.
    
    [Idea]
        - Use two array to traverse the character in strings, return false if mapping value doesn't match.

    [Complexity]
        - Time : O(n), where n is the number of elements of the given array.
        - Space : O(n).
"""
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int map1[256] = {}, map2[256] = {0}, n = s.size();
        for(int i=0; i<n; i++){
            if((map1[s[i]] || map2[t[i]]) && (map1[s[i]] != t[i] || map2[t[i]] != s[i])) return false;
            map1[s[i]] = t[i];
            map2[t[i]] = s[i];
        }
        return true;

    }

};