"""  [Problem]
        - Given two strings s and t, return true if t is an anagram of s, and false otherwise.

    [Idea]
        - Use dictionary in Python to get unique characters in the given string.

    [Complexity]
        - Time : O(n), where n is the max size of the given string.
        - Space : O(n), use dictionary for extra space to store unique values.
"""

class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        # return sorted(s) == sorted(t)
        if len(s) != len(t):
            return False
        tracker = collections.defaultdict(int)
        for c in s : 
            tracker[c] +=1 
        
        for c in t : 
            tracker[c] -=1
            if tracker[c] < 0 : return False
        return True