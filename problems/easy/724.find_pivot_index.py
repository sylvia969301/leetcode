"""  [Problem]
        - Given an array of integers nums, calculate the pivot index of this array.
        - The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
        - Return the leftmost pivot index. If no such index exists, return -1.
*   [Idea]
        - Define left_sum and right_sum and initialized by 0 and sum of the given array.
        - right_sum decrease by nums[i], left_sum increase by nums[i] each iteration.
        - return index if left_sum equals to right_sum.
        - return -1 if couldn't find the index that satisfies conditions in the problem statement.
    [Complexity]
        - Time : O(n), where n is the size of the given array.
        - Space : O(1).
"""

class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left_sum, right_sum = 0, sum(nums)

        for i in range(len(nums)):
            right_sum -= nums[i]
            if left_sum == right_sum:
                return i
            left_sum += nums[i]
        return -1