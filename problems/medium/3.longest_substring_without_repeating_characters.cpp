#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
/*  [Problem]
        - Given a string s, find the length of the longest substring without repeating characters.
*   [Idea]
        - Define dictionary store with character-index pair.
        - Use sliding window method (move left and right pointer)
        - Store in dictionary if havn't appeared before.
        - calculate max length(counter) each iteration.
    [Complexity]
        - Time : O(n), where len(s)=n.
        - Space : O(n), use dictionary to store character-index pairs, 
                    where m is the size of the character set..
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> char_map;
        int counter = 0 ;
        int right = 0;
        int left = 0;

        while(left < s.size() && right < s.size()){
            char c = s[right];
            if(char_map.count(c) >0){
                left = max(left, char_map[c]+1);
            }
            char_map[c] = right;
            counter = max(counter, right - left +1);
            right +=1;
            
        }
        return counter;
    }
};