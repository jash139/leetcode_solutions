class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (board[row][col] == '.')
                    continue;
                if (!isValueAtPositionValid(row, col, board)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValueAtPositionValid(int row, int col, vector<vector<char>> board) {
        char value = board[row][col];
        
        bool isRowValid = true;
        bool isColValid = true;
        
        for (int rowIdx = 0; rowIdx < board.size(); ++rowIdx) {
            if (rowIdx != row and board[rowIdx][col] == value) {
                isRowValid = false;
                break;
            }
        }
        for (int colIdx = 0; colIdx < board.size(); ++colIdx) {
            if (colIdx != col and board[row][colIdx] == value) {
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
                
                if (rowToCheck == row or colToCheck == col)
                    continue;
                
                if (board[rowToCheck][colToCheck] == value)
                    return false;
            }
        }
        
        return true;
    }
};
