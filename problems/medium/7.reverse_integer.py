
"""  [Problem]
        - Given a signed 32-bit integer x, return x with its digits reversed.
        - If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
*   [Idea]
        - Traverse from tail to head of the stringfied integer.
    [Complexity]
        - Time : O(n), where n is the digits of the given number x.
        - Space : O(n).
"""


class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        isNegative = False
        
        reversedX = ''
        if x <0 :
            isNegative = True
            x = -x
        
        s = str(x)
        for i in range(len(s)-1, -1, -1):
            reversedX += s[i]
        reversedInt = int(reversedX)
        if isNegative : reversedInt = -reversedInt

        if reversedInt < -2**31 or reversedInt > 2**31: return 0

        return reversedInt