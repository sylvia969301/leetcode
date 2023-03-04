#include <string>
#include <vector>
using namespace std;
/* [Problem]
        - Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

*   [Idea]
        - Use Depth First Tree method to generate parentheses.
    [Complexity]
        - Time : O(n^2).
        - Space : O(n^2).
*/

class Solution {
public:

    vector<string> result;

    void dfs(int left, int right, string s, int n){
        if (s.length() == n*2){
            result.push_back(s);
            return;
        }
        if(left < n){
            dfs(left+1, right, s+"(", n);
        }
        if(right < left){
            dfs(left, right+1, s+")", n);
        }

    }

    vector<string> generateParenthesis(int n) {
        dfs(0, 0, "", n);
        return result;
    }
};