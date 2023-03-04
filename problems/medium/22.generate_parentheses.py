"""  [Problem]
        - Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

*   [Idea]
        - Use "Depth First Search (DFS)" method to generate parentheses.
    [Complexity]
        - Time : O(n^2).
        - Space : O(n^2).
"""
class Solution(object):
    def generateParentheses(self, n):
        """
        :type n : int
        :rtype: List[str]
        """

        def dfs(left, right, addString):
            if len(addString) == n*2:
                result.append(addString)
                return

            if left < n:
                dfs(left+1, right, addString+'(')

            if right < left:
                dfs(left, right+1, addString+')')

        result = []
        dfs(0, 0, '')
        return result    