"""  [Problem]
        - Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
        - Return the sum of the three integers.
*   [Idea]
        - let the given list be sorted.
        - total = curret value + left pointer + right pointer
        - make sure the gap between target and total is minimized.
        - move the pointer of left and right untill they meet each other.
    [Complexity]
        - Time : O(n^2), where len(nums) = n.
        - Space : O(1).
"""

class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        closestSum = float("inf")
        nums.sort()

        for i in range(len(nums)-2):
            if i > 0 and nums[i] == nums[i-1]:
                continue

            left = i+1
            right = len(nums) -1
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                if total == target:
                    return total
                if abs(total - target) < abs(closestSum - target):
                    closestSum = total 
                if total < target:
                    left +=1
                else :
                    right -=1

        return closestSum