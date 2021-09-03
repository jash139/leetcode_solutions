class Solution {
public:
    // O(n ^ 2) Time | O(n ^ 2) Space
    // n : input size
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiralMatrix(n, vector<int> (n, 0));
        
        int curNum = 1;
        
        int startRow = 0;
        int endRow = n - 1;
        int startCol = 0;
        int endCol = n - 1;
        
        while (startRow <= endRow and startCol <= endCol) {
            for (int col = startCol; col <= endCol; ++col) {
                spiralMatrix[startRow][col] = curNum++;
            }
            
            for (int row = startRow + 1; row <= endRow; ++row) {
                spiralMatrix[row][endCol] = curNum++;
            }
            
            for (int col = endCol - 1; col >= startCol; --col) {
                if (startRow == endRow)
                    break;
                
                spiralMatrix[endRow][col] = curNum++;
            }
            
            for (int row = endRow - 1; row > startRow; --row) {
                if (startCol == endCol)
                    break;
                
                spiralMatrix[row][startCol] = curNum++;
            }
            
            startRow++;
            endRow--;
            
            startCol++;
            endCol--;
        }
        
        return spiralMatrix;
    }
};
