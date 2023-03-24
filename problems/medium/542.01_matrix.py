"""  [Problem]
        - Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
        - The distance between two adjacent cells is 1.
*   [Idea]
        - Use BFS method, on zero cells first.
        - Start from the root, set root.left.next = root.right, if have root.right.
        - set root.right.next = root.next.left, if have root.next(cross the left and right subtrees)
    [Complexity]
        - Time : O(N * M), where N, M is the numbers of row and columns of the given matrix.
        - Space : O(N * M), since need the space for the queue.
"""


class Solution(object):
    def updateMatrix(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[List[int]]
        """

        q = deque()
        visited = set()
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j] == 0 and (i, j) not in visited:
                    q.append((i, j))
                    visited.add((i, j))
                else:
                    mat[i][j] = '#'

        # Find the closest island from zeros
        while q:
            x, y = q.popleft()
            for dr, dc in [(0, 1), (0, -1), (-1, 0), (1, 0)]:
                newX, newY = x + dr, y + dc
                if len(mat) > newX >= 0 and len(mat[0]) > newY >= 0 and mat[newX][newY] == '#':
                    mat[newX][newY] = mat[x][y] + 1
                    q.append((newX, newY))
        return mat
