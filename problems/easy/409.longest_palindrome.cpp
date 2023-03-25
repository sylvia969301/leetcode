
#include <string>
#include <unordered_map>
using namespace std;
/*
"""  [Problem]
        - Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
        - Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

*   [Idea]
        - Use Hash Table (Unordered map in C++) to store the frequency of every character.
        - If freq is a even number, directly add to result.
        - If freq is a odd number, add freq - 1 to result and set oddFound = True.
        - At the end, result += 1 if oddFound (Since we can add the char at the center position of the paindrome)
    [Complexity]
        - Time : O(N), where N is the length of unique characters in the given string.
        - Space : O(N), use hash table (Unordered map in C++) for extra space.
"""
*/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;
        int result = 0;
        bool foundOdd = false;

        for(auto c : s ){
            counts[c] +=1 ;
        }
        for(auto &c : counts){
            if(c.second % 2 == 0) result += c.second;
            else{
                foundOdd = true;
                result += c.second -1;
            }
        }
        if(foundOdd) result += 1;
        return result;
    }
};