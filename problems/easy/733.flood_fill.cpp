#include <vector>
using namespace std;
/*

"""  [Problem]
        - An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
*   [Idea]
        - Use DFS (Depth First Search) to fill the color of given array of image representation.
        - From (sr, sc) expand around, until meet boundary conditions.
    [Complexity]
        - Time : O(N*M), where N and M are the lengths of the sides of the given image.
        - Space : O(L), where L is the size of largest continuous blocks in the given image.
"""
*/

class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int originColor, int color){
        int rows = image.size();
        int cols = image[0].size();

        if( r < 0 || c < 0 || r > rows-1 || c> cols -1 || image[r][c]==color || image[r][c]!=originColor){
            return;
        }
        image[r][c] = color;
        dfs(image, r-1, c, originColor, color);
        dfs(image, r+1, c, originColor, color);
        dfs(image, r, c+1, originColor, color);
        dfs(image, r, c-1, originColor, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originColor = image[sr][sc];
        dfs(image, sr, sc, originColor, color);
        return image;
    }
};