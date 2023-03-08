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
        dict = {}
        left = 0
        right = 0
        counter = 0

        while left < len(s) and right < len(s):
            char = s[right]
            if char in dict:
                left = max(left, dict[char]+1)
            dict[char] = right
            counter = max(counter, right - left +1)
            right +=1
        return counter