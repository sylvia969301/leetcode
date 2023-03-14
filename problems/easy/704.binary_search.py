"""  [Problem]
        - Given an array of integers nums which is sorted in ascending order, 
            and an integer target, write a function to search target in nums. 
            If target exists, then return its index. Otherwise, return -1.

    [Complexity]
        - Time : O(log n), where n is the number of elements of the given array.
        - Space : O(1).
"""

class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = (left + right ) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                right = mid -1
            else:
                left = mid +1
        return -1
