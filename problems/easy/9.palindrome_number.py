"""  [Problem]
        - Given an integer x, return true if x is a 
          palindrome, and false otherwise.
*   [Idea]
        - Use left and right pointer.
        - compare each of them, False if left != right
        - left+=1, right-=1 until they meet each other.
    [Complexity]
        - Time : O(n), where n=len(str(x))
        - Space : O(1).
"""


class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        string = str(x)
        left = 0
        right = len(string) - 1

        while left < right:
            if string[left] != string[right]:
                return False
            left +=1
            right -=1
        return True