
"""  [Problem]
        - Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

    [Idea]
        - Use two pointers to iterate the given array
        - swap values each iteration until two pointers meet each other.

    [Complexity]
        - Time : O(N)
        - Space : O(n) change result in-place.
"""

class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        splitText = s.split(' ')
        s = map(lambda x: x[::-1], splitText)
        
        return ' '.join(s)
