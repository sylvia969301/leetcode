#include <unordered_map>
#include <string>

using namespace std;
/* [Problem]
        - Given a roman numeral, convert it to an integer.
*   [Idea]
        - Make an dictionary store with roman-integer pair.
        - substract value if s[i] < s[i+1]
        - add value if s[i] > s[i+1]
    [Complexity]
        - Time : O(n), where len(s)=n.
        - Space : O(1).
*/

class Solution{
public:
    int romanToInt(string s){
        int result = 0;
        unordered_map <char, int> roman{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        for(int i=0; i<s.size(); i++){
            if( i+1 < s.size() && roman[s[i]] < roman[s[i+1]]){
                result -= roman[s[i]];
            }
            else{
                result += roman[s[i]];
            }
        }
        return result;
    }


};