
"""  [Problem]
        - Given an integer array nums, find the subarray with the largest sum, 
           and return its sum.
*   [Idea]
        - Use Dynamic Programming(DP), 
          since the calculation of each state can be stored and reused.
    [Complexity]
        - Time : O(n), where n is the size of the given array nums.
        - Space : O(n).
"""

class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        arr = []
        arr.append(nums[0])
        maxNum = arr[0]

        for i in range(1, len(nums)):

            arr.append(max(nums[i], arr[i-1] + nums[i]))
            maxNum = arr[i] if arr[i] > maxNum else maxNum

        return maxNum