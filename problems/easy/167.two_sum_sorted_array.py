"""  [Problem]
        - Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
        find two numbers such that they add up to a specific target number. 
        Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

    [Idea]
        - Use two pointer(left and right), sum up two vlaue of they point to, 
        - left += 1, if target less than summation.
        - right -=1, if target greater than summation.

    [Complexity]
        - Time : O(N)
        - Space : O(1) change result in-place.
"""

class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        l, r = 0, len(numbers)-1
        while l<r:
            if numbers[l] + numbers[r] == target: return [l+1, r+1]
            if numbers[l] + numbers[r] < target: l+=1
            else: r -=1