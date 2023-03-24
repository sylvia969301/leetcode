#include <vector>
#include <queue>
using namespace std;
/*
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
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if ( grid.empty()) return 0;

        int fresh = 0, N = grid.size(), M = grid[0].size();
        queue<pair<int, int>> rotten;
        int times = 0;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M ; j++){

                if(grid[i][j] == 2) 
                    rotten.push({i, j});
                    
                else if(grid[i][j] == 1) 
                    fresh += 1;
            }
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!rotten.empty() && fresh > 0){
            int qsize = rotten.size();

            for( int i = 0; i < qsize; i++){

                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();

                for(auto d : dirs){
                    int newX = x + d.first, newY = y + d.second;

                    if( N > newX && newX >=0 && M > newY && newY >=0 && grid[newX][newY] == 1){
                        grid[newX][newY] = 2;
                        fresh -= 1;
                        rotten.push({newX, newY});
                    }
                }
            }
            times += 1;
        }

        return fresh !=0 ? -1 : times;

    }
};