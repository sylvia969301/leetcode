"""  [Problem]
        - Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
        - Return the running sum of nums.
*   [Idea]
        - Use for loop to iterate through all the elements of nums.
        - nums[i] += nums[i-1]
    [Complexity]
        - Time : O(n), where the length of given list is n.
        - Space : O(1).
"""

class Solution(object):
    def runningSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for i in range(1, len(nums)):
            nums[i] += nums[i-1]
        return nums