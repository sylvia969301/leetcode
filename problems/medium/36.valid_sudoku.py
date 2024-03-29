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
class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        cols = collections.defaultdict(set)
        rows = collections.defaultdict(set)
        squares = collections.defaultdict(set) #key = (row//3, col//3)

        for r in range(9):
            for c in range(9):
                if board[r][c] == "." : continue
                if (board[r][c] in rows[r]) or (board[r][c] in cols[c]) or (board[r][c] in squares[(r//3, c//3)]):
                    return False
                rows[r].add(board[r][c])
                cols[c].add(board[r][c])
                squares[(r//3, c//3)].add(board[r][c])
        return True