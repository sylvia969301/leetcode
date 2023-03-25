
"""  [Problem]
        - Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
        - Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

*   [Idea]
        - Use Hash Table (Dictionary in Python) to store the frequency of every character.
        - If freq is a even number, directly add to result.
        - If freq is a odd number, add feq - 1 to result and set oddFound = True.
        - At the end, result += 1 if oddFound (Since we can add the char at the center position of the paindrome)
    [Complexity]
        - Time : O(N), where N is the length of unique characters in the given string.
        - Space : O(N), use hash table (dictionary in Python) for extra space.
"""

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """

        counts = {} # hash table 
        result, oddFound = 0, False

        for c in s :
            counts[c] = counts.get(c, 0) + 1
        
        for c, nums in counts.items():
            if nums % 2 == 0 :
                result += nums
            else:
                oddFound = True
                result += nums - 1

        if oddFound : result += 1
        return result
        
        