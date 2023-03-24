"""  [Problem]
        - You are given an m x n grid where each cell can have one of three values:
            0 representing an empty cell,
            1 representing a fresh orange, or
            2 representing a rotten orange.
        - Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
        - Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
          If this is impossible, return -1.

*   [Idea]
        - Use BFS method, loop through grids to find fresh(1) and rotten oranges(2).
        - If there are fresh and rotten oranges to loop through, 
          determine if any fresh orange will become rotten in four directions(left, right, top, bottom) from the coordinates of rotten oranges.
        - If there still have fresh oranges remaining, return -1, else return nums of iterations.
    [Complexity]
        - Time : O(N * M), where N, M is the numbers of row and columns of the given matrix.
        - Space : O(K), where K is the max number of rotten oranges need to be stored in the queue.
"""

class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        fine, rotten = set(), deque()
        result = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1 :
                    fine.add((i, j))
                elif grid[i][j] == 2:
                    rotten.append((i, j))
        
        while fine and rotten:
            for _ in range(len(rotten)):
                x, y = rotten.popleft()
                for coord in [(x-1, y), (x+1, y), (x, y-1), (x, y+1)]:
                    if coord in fine: 
                        fine.remove(coord)
                        rotten.append(coord)
            result += 1
        return -1 if fine else result