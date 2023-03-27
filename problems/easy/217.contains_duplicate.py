"""  [Problem]
        - Given an integer array nums, 
          return true if any value appears at least twice in the array, 
          and return false if every element is distinct.

    [Idea]
        - Use set in Python to get unique values in the given array.

    [Complexity]
        - Time : O(n), where n is the size of the given array.
        - Space : O(n), use set for extra space to store unique values.
"""

class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        hashset = set()
        for n in nums:
            if n in hashset:
                return True
            hashset.add(n)
        return False
