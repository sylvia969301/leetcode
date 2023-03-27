"""  [Problem]
        - Given an array of integers nums and an integer target, 
          return indices of the two numbers such that they add up to target.

    [Idea]
        - Use dictionary in Python to get unique numbers in the given list.
        - Search the dictionary by complement, return indices if found, else insert values.

    [Complexity]
        - Time : O(n), where n is the max size of the given list.
        - Space : O(n), use dictionary for extra space to store unique values.
"""

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        searchMap = {}
        for i, num in enumerate(nums):
            diff = target - num
            if diff in searchMap :
                return [searchMap[diff], i]
            searchMap[num] = i
        return