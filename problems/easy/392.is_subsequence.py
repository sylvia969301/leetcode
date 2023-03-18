
"""  [Problem]
        - Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
*   [Idea]
        - Using two pointers (i and j) 
        - i += 1 if meet same characters, else only j+=1
        - if i == len(s), it means found the required number of characters in subsequence.
    [Complexity]
        - Time : O(n + m), where n is the size of the given subsequence s, m is the given size of string.
        - Space : O(1).
"""

class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        i, j = 0,0 
        while i<len(s) and j < len(t):
            if s[i] == t[j]:
                i+=1
            j+=1
        return i == len(s)