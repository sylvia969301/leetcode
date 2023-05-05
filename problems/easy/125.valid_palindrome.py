"""  [Problem]
        - Given a string s, return true if it is a palindrome, or false otherwise.
*   [Idea]
        - Use two pointers and a helper function isAlphaNum which checks ASCII by determine whether it's a alpha/number or not.
    [Complexity]
        - Time : O(N), where N is the length of the given array of prices.
        - Space : O(1), constant space.
"""

class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l = 0
        r = len(s)-1
        while l < r:
            while l < r and not self.isAlphaNum(s[l]) : l+=1
            while r > l and not self.isAlphaNum(s[r]) : r-=1
            if s[l].lower() != s[r].lower():
                return False
            l +=1
            r -=1
        
        return True

    def isAlphaNum(self, c):
        return (ord('A') <= ord(c) <= ord('Z') or
                ord('a') <= ord(c) <= ord('z') or
                ord('0') <= ord(c) <= ord('9'))