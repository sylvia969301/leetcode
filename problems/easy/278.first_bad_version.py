
"""  [Problem]
        - Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one,
          which causes all the following ones to be bad.
        - You are given an API bool isBadVersion(version) which returns whether version is bad.
          Implement a function to find the first bad version. You should minimize the number of calls to the API.
    [Idea]
        - Using Binary Search Method, divide from the middle and move two pointers.
        - set right pointer = middle, if NOT broken.
        - set left pointer = middle + 1, if broken.
    [Complexity]
        - Time : O(log n), where n is the number of elements of the given numbers.
        - Space : O(1).
"""

# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1 : return n
        left, right = 0, n
        
        while left < right:
            mid = (left + right) // 2
            if isBadVersion(mid):
                right = mid 
            else:
                left = mid +1
        return left