class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solvePartialSudoku(board, 0, 0);
    }
    
    bool solvePartialSudoku(vector<vector<char>> &board, int row, int col) {
        if (row == board.size())
            return true;
        
        if (col == board[row].size()) {
            return solvePartialSudoku(board, row + 1, 0);
        }
        
        if (board[row][col] != '.') {
            return solvePartialSudoku(board, row, col + 1);
        }
        
        for (char digit = '1'; digit <= '9'; ++digit) {
            if (isValidAtPosition(digit, row, col, board)) {
                board[row][col] = digit;
                if (solvePartialSudoku(board, row, col + 1)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    
    bool isValidAtPosition(char value, int row, int col, vector<vector<char>> board) {
        bool isRowValid = true;
        bool isColValid = true;
        
        for (int rowIdx = 0; rowIdx < 9; ++rowIdx) {
            if (board[rowIdx][col] == value) {
                isRowValid = false;
                break;
            }
        }
        
        for (int colIdx = 0; colIdx < 9; ++colIdx) {
            if (board[row][colIdx] == value) {
                isColValid = false;
                break;
            }
        }
        
        if (!isRowValid or !isColValid)
            return false;
        
        int subgridRowStart = (row / 3) * 3;
        int subgridColStart = (col / 3) * 3;
        
        for (int rowIdx = 0; rowIdx < 3; ++rowIdx) {
            for (int colIdx = 0; colIdx < 3; ++colIdx) {
                int rowToCheck = subgridRowStart + rowIdx;
                int colToCheck = subgridColStart + colIdx;
                
                if (board[rowToCheck][colToCheck] == value)
                    return false;
            }
        }
        
        return true;
    }
};
