
"""  [Problem]
        - Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

    [Complexity]
        - Time : O(n).
        - Space : O(1).
"""

class Solution(object):

    def reverse(self, nums, start, end):
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start, end = start+1, end-1
        return nums

    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        k = k % len(nums)
        if k < 0:
            k = k+len(nums)
        
        nums = self.reverse(nums, 0, len(nums)-1)
        nums = self.reverse(nums, 0, k-1)
        nums = self.reverse(nums, k, len(nums)-1)
