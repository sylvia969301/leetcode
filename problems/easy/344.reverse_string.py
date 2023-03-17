
"""  [Problem]
        - Write a function that reverses a string. The input string is given as an array of characters s.

    [Idea]
        - Use two pointers to iterate the given array
        - swap values each iteration until two pointers meet each other.

    [Complexity]
        - Time : O(N)
        - Space : O(1) change result in-place.
"""

class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        left, right = 0, len(s) -1
        while left < right :
            s[left], s[right] = s[right], s[left]
            left +=1
            right -=1
        return s