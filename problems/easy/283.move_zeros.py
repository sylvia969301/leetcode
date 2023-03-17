
"""  [Problem]
        - Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    [Idea]
        - Use i to keep track of position of the first zero in the list (which changes as we go).
        - usejto keep track of the first non-zero value after the first zero (which is pointed by i).
        - Each time we have i correctly points to a zero and j correctly points to the first non-zero after i, we swap the values that store at i and j.

    [Complexity]
        - Time : O(N)
        - Space : O(1) change result in-place.
"""
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        zero = 0
        for i in range(n):
            if nums[i] != 0:
                nums[i], nums[zero] = nums[zero], nums[i]
                zero += 1
            