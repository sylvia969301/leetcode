"""  [Problem]
        - Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

    [Complexity]
        - Time : O(n).
        - Space : O(n), use extra space .
"""

class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ## O(nlogn)
        # return sorted([num **2 for num in nums])
        ## O(n)
        l, r = 0, (len(nums)-1)
        res = []
        while l <= r:
            if abs(nums[l]) > abs(nums[r]):
                res.append(nums[l] **2 )
                l +=1
            else:
                res.append(nums[r] **2 )
                r -=1
        return res[ :: -1]