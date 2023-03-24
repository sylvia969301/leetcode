#include <vector>
using namespace std;
/*
"""  [Problem]
        - Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
        - The distance between two adjacent cells is 1.
*   [Idea]
        - Use DP (Dynamic Programming) method, skip zero-cells.
        - Start scanning grids from the most left-top one, 
          if the grid has left or top neighbor, mat[r][c] = min(left, top) + 1.
        - Start scanning grids from the right-bottom one, 
          if the grod has right or bottom neighbor, mat[r][c] = min(mat[r][c], min(right, bottom)+1 ).
          
    [Complexity]
        - Time : O(N * M), where N, M is the numbers of row and columns of the given matrix.
        - Space : O(1), since directly change the value in-space.
"""
*/


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int N = mat.size(), M = mat[0].size(), INF = N+M;

        for (int r = 0; r < N; r++){
            for(int c = 0; c < M; c++){
                if(mat[r][c] == 0) continue;
                int left = INF, top = INF;
                if( r-1 >= 0) top = mat[r-1][c];
                if( c-1 >= 0) left = mat[r][c-1];
                mat[r][c] = min(top, left) +1;
            }
        }

        for(int r = N-1; r >= 0 ; r--){
            for(int c = M-1; c >=0 ; c--){
                if(mat[r][c] == 0) continue;
                int right = INF, bottom = INF;
                if(r + 1 < N) bottom = mat[r+1][c];
                if(c + 1 < M) right = mat[r][c+1];
                mat[r][c] = min(mat[r][c], min(bottom, right)+1);
            }
        }
        return mat;
    }
};