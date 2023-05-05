#include <string>
#include <stack>
using namespace std;

/*
"""  [Problem]
        - Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
*   [Idea]
        - Use dictionary which store key-value pair of open/closing parentheses and stack structure.
        - 
    [Complexity]
        - Time : O(N), where N is the length of the given array of prices.
        - Space : O(N), stack can up to input size.
"""
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c : s){
            if (c=='(' || c =='{' || c == '['){
                stk.push(c);
            }
            else {
                if(stk.empty()) return false;
                if(c==')' && stk.top()=='('){
                    stk.pop();
                }else if(c=='}' && stk.top()=='{'){
                    stk.pop();
                }else if(c==']' && stk.top()=='['){
                    stk.pop();
                }else{
                    return false;
                }

            }
        }
        return stk.empty();
    }
};