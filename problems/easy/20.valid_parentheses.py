"""  [Problem]
        - Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
*   [Idea]
        - Use dictionary which store key-value pair of open/closing parentheses and stack structure.
        - 
    [Complexity]
        - Time : O(N), where N is the length of the given array of prices.
        - Space : O(N), stack can up to input size.
"""

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        openToClose = {'(':')', '{':'}', '[':']'}
        for pattern in s :
            if pattern in openToClose: #1
                stack.append(pattern) 
            elif len(stack)==0 or openToClose[stack.pop()] != pattern: #2
                return False
        
        return len(stack)==0 #3
    
    # 1. if it's the left bracket then we append it to the stack
    # 2. else if it's the right bracket and the stack is empty(meaning no matching left bracket), or the left bracket doesn't match
    # 3. finally check if the stack still contains unmatched left bracket