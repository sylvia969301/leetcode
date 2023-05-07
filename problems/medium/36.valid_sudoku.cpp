#include <vector>
#include <map>
using namespace std;
/*
"""  [Problem]
        - Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
            - Each row must contain the digits 1-9 without repetition.
            - Each column must contain the digits 1-9 without repetition.
            - Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
*   [Idea]
        - Use dictionary which store key-value pair of number set of rows/cols/squares .
    [Complexity]
        - Time : O(N^2), where N is the row/col size of the sudoku board.
        - Space : O(N), stack can up to input sudoku board size.
"""
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, int> rows[9], cols[9], squares[9];

        for(int r = 0; r <9; r++){
            for(int c = 0; c < 9 ; c++){
                if(board[r][c] !='.'){
                    int num = board[r][c];
                    if(rows[r][num]>0 || cols[c][num]>0 || squares[r/3*3+c/3][num] >0){
                        return false;
                    }
                    rows[r][num] +=1;
                    cols[c][num] +=1;
                    squares[r/3*3+c/3][num] +=1;
                    // for (auto it = rows[r].begin(); it != rows[r].end(); it++) {
                    //     std::cout << "id: " << (*it).first << ", name: " << (*it).second << "\n";
                    // }
                }
            }
        }
        return true;
    }
};