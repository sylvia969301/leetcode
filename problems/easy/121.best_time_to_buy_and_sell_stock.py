"""  [Problem]
        - You are given an array prices where prices[i] is the price of a given stock on the ith day.
        - You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
        - Return the maximum profit you can achieve from this transaction. 
          If you cannot achieve any profit, return 0.

*   [Idea]
        - Use DP(Dynamic Programming) method, loop through prices and record the maxProfit we can get.
    [Complexity]
        - Time : O(N), where N is the length of the given array of prices.
        - Space : O(1), constant space.
"""

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        left, right, maxProfit = 0, 1, 0
        while right < len(prices):
            profit = prices[right] - prices[left]
            if prices[right] > prices[left]:
                maxProfit = max(profit, maxProfit)
            else: 
                left = right
            right += 1
        return maxProfit
