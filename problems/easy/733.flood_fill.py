
"""  [Problem]
        - An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
*   [Idea]
        - Use DFS (Depth First Search) to fill the color of given array of image representation.
        - From (sr, sc) expand around, until meet boundary conditions.
    [Complexity]
        - Time : O(n), where n is the size of the given array.
        - Space : O(1), since we change value in-space.
"""

class Solution(object):


    def floodFill(self, image, sr, sc, color):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type color: int
        :rtype: List[List[int]]
        """
        rows = len(image)
        cols = len(image[0])
        originColor = image[sr][sc]

        def dfs(r, c):

            if r <0 or c <0 or r>rows-1 or c > cols-1 or image[r][c]==color or image[r][c]!=originColor:
                return 
            image[r][c] = color   
            dfs(r+1, c)
            dfs(r-1, c)
            dfs(r, c+1)
            dfs(r, c-1)

        dfs(sr, sc)
        return image
        

    