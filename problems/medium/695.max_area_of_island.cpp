#include <vector>
using namespace std;
/*

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
*/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int maxArea = 0;
        for(int i=0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j]) maxArea = max(maxArea, dfs(grid, i, j));
            }
        }
        return maxArea;
    }
private : 
    int rows, cols;
    int dfs(vector<vector<int>> & grid, int r, int c){
        if(r <0 || c <0 || r > rows-1 || c > cols -1) return 0;
        if(! grid[r][c]) return 0;
        grid[r][c] = 0;
        return 1 + dfs(grid, r+1, c) + dfs(grid, r-1, c) + dfs(grid, r, c+1) + dfs(grid, r, c-1);
    }
};
