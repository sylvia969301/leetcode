"""  [Problem]
        - Given a string s, find the length of the longest substring without repeating characters.
*   [Idea]
        - Define dictionary store with character-index pair.
        - Use sliding window method (move left and right pointer)
        - Store in dictionary if havn't appeared before.
        - calculate max length(counter) each iteration.
    [Complexity]
        - Time : O(n), where len(s)=n.
        - Space : O(min(m, n)), use dictionary to store character-index pairs,
                    where m is the size of the character set.
"""

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        charSet = set()
        left = 0
        res = 0
        
        for right in range(len(s)):
            char = s[right]
            while char in charSet:
                charSet.remove(s[left])
                left += 1

            charSet.add(char)
            res = max(res, right - left+1)
        return res

            