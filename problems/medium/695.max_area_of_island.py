
"""  [Problem]
        - You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
          You may assume all four edges of the grid are surrounded by water.
*   [Idea]
        - Use DFS (Depth First Search) to search the max continuous grid of the given array .
        - search n*m times where n and m are the lengths of the sides of the given array.
        - each time compare with grid[r][c] with the maxArea.
    [Complexity]
        - Time : O(N*M), where N and M are the lengths of the sides of the given grid.
        - Space : O(L), where L is the size of largest continuous blocks in the given grid.
"""


class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows = len(grid)
        cols = len(grid[0])
        maxArea = 0

        def dfs(r, c):
            if r<0 or c <0 or r>rows - 1 or c > cols -1 : return 0
            if not grid[r][c] : return 0
            grid[r][c] = 0

            return 1 + dfs(r+1, c) + dfs(r-1, c) + dfs(r, c+1) + dfs(r, c-1)
        
        for r, c in product(range(rows), range(cols)):
            if grid[r][c] : maxArea = max(dfs(r, c), maxArea)
        return maxArea