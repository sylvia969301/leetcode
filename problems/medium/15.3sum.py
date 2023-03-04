"""  [Problem]
        - Given an integer array nums, 
            return all the triplets [nums[i], nums[j], nums[k]] 
            such that i != j, i != k, and j != k, 
            and nums[i] + nums[j] + nums[k] == 0.
    [Idea]
        - Sum up current number, left pointer, right pointer.
        - append to result if summation == 0, 
        - left pointer +=1 if sum <0 ; right pointer -=1 if sum >0

    [Complexity]
        - Time : O(n^2).
        - Space : O(n).
"""

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) <3:
            return []
        
        nums.sort()
        result = []

        for i in range(len(nums) - 2):
            if i>0 and nums[i] == nums[i-1]:
                continue
            
            left = i+1
            right = len(nums)-1

            while left < right:
                sum = nums[i] + nums[left] + nums[right]
                if sum ==0:
                    result.append([nums[i], nums[left], nums[right]])
                    left +=1
                    right -=1

                    while nums[left] == nums[left-1] and left <right:
                        left +=1
                    
                    while nums[right] == nums[right+1] and left < right:
                        right-=1
                        
                elif sum <0:
                    left +=1
                else :
                    right-=1
                    
        return result