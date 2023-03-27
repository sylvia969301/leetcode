#include <string>
#include <unordered_map>
using namespace std;
/*
"""  [Problem]
        - Given two strings s and t, return true if t is an anagram of s, and false otherwise.

    [Idea]
        - Use unordered map in C++ to get unique characters in the given string.

    [Complexity]
        - Time : O(n), where n is the max size of the given string.
        - Space : O(n), use unordered map for extra space to store unique values.
"""
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;
        if (s.size()!=t.size()) return false;
        unordered_map<char, int> map;
        for(auto c : s) map[c] += 1;

        for(auto c : t){
            map[c] -= 1;
            if(map[c] < 0) return false;
        }
        return true;
    }
};