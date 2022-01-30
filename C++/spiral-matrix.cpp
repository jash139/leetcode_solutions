class Solution {
public:
    // O(n) Time | O(n) Space
    // n : total number of elements in the array
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        
        int startRow = 0;
        int endRow = matrix.size() - 1;
        
        int startCol = 0;
        int endCol = matrix[0].size() - 1;
        
        while (startRow <= endRow and startCol <= endCol) {
            for (int col = startCol; col <= endCol; ++col)
                result.push_back(matrix[startRow][col]);
            
            for (int row = startRow + 1; row <= endRow; ++row)
                result.push_back(matrix[row][endCol]);
            
            for (int col = endCol - 1; col >= startCol; --col) {
                // When there's single row left in the middle of the matrix
                if (startRow == endRow)
                    break;
                result.push_back(matrix[endRow][col]);
            }
            
            for (int row = endRow - 1; row >= startRow + 1; --row) {
                // When there's single col left in the middle of the matrix
                if (startCol == endCol)
                    break;
                result.push_back(matrix[row][startCol]);
            }
            
            startRow++;
            endRow--;
            
            startCol++;
            endCol--;
        }
        
        return result;
    }
};
