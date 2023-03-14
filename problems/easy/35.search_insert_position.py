"""  [Problem]
        - Given a sorted array of distinct integers and a target value,
          return the index if the target is found. If not, 
          return the index where it would be if it were inserted in order.
    
    [Idea]
        - Use Binary Search method , solve the problem by moving left and right pointers.

    [Complexity]
        - Time : O(log n), where n is the number of elements of the given array.
        - Space : O(1).
"""

class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left , right = 0, len(nums)-1

        while left <= right :
            mid = (left + right) // 2

            if nums[mid] == target : return mid
            elif nums[mid] < target : left = mid +1
            else: right = mid -1
        return left