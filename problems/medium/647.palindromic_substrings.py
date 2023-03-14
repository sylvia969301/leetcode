### Expand Around the Center
"""  [Problem]
        - Given a string s, return the number of palindromic substrings in it.
        - A string is a palindrome when it reads the same backward as forward.
        - A substring is a contiguous sequence of characters within the string.
*   [Idea]
        - Using 中心擴張法(Expand Around the Center), expand if s[left]==s[right].
        - Check 2 chars (even) and 3 chars(odd) that contains longest palindrome each time.
    [Complexity]
        - Time : O(n^2), where n is the size of the given array.
        - Space : O(1).
"""

class Solution(object):
    
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """

        oddPalindrome, evenPalindrome = 0, 0
        for i in range(len(s)):
            evenPalindrome += self.expandAroundTheCenter(s, i, i+1)
            oddPalindrome += self.expandAroundTheCenter(s, i, i)

        return oddPalindrome + evenPalindrome


    def expandAroundTheCenter(self, s, left, right):
        count = 0
        while left >=0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right +=1
            count +=1
        return count