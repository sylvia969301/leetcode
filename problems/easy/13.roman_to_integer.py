
"""  [Problem]
        - Given a roman numeral, convert it to an integer.
*   [Idea]
        - Make an dictionary store with roman-integer pair.
        - substract value if s[i] < s[i+1]
        - add value if s[i] > s[i+1]
    [Complexity]
        - Time : O(n), where len(s)=n.
        - Space : O(1).
"""

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman = {'I': 1,
                'V': 5,
                'X': 10,
                'L': 50,
                'C': 100,
                'D': 500,
                'M': 1000}
            
        result = 0
        for a, b in zip(s, s[1:]):
            if roman[a] < roman[b]:
                result -= roman[a]
            else:
                result += roman[a]
        return result + roman[s[-1]]
    
class Solution_2(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman = {'I': 1,
                'V': 5,
                'X': 10,
                'L': 50,
                'C': 100,
                'D': 500,
                'M': 1000}
            
        for i in range(len(s)):
            if i+1 < len(s) and roman[s[i]] < roman[s[i+1]]:
                result -= roman[s[i]]
            else:
                result += roman[s[i]]

        return result 