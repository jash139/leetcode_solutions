class Solution {
public:
    // O(mn) Time | O(mn) Space 
    // m and n are height and width of the matrix
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        int maxSquareLength = 0;
        
        for (int row = 1; row < matrix.size() + 1; ++row) {
            for (int col = 1; col < matrix[0].size() + 1; ++col) {
                // dp has one extra row and col therefore
                // to access in matrix we are doing -1
                if (matrix[row - 1][col - 1] == '1') {
                    dp[row][col] = min(dp[row - 1][col - 1], min(dp[row - 1][col], dp[row][col - 1])) + 1;
                    maxSquareLength = max(maxSquareLength, dp[row][col]);
                }
            }
        }
        
        int maxSquareArea = maxSquareLength * maxSquareLength;
        return maxSquareArea;
    }
    
    // O((mn) ^ 2) Time | O(1) Space
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int rowSize = matrix.size();
//         int colSize = matrix[0].size();
        
//         int maxSquareLength = 0;
        
//         for (int row = 0; row < rowSize; ++row) {
//             for (int col = 0; col < colSize; ++col) {
//                 if (matrix[row][col] == '0') {
//                     continue;
//                 }
                
//                 int currSquareLength = 1;
//                 bool hasZero = false;
//                 int curRow = row + 1;
//                 int curCol = col + 1;
                
//                 while (curRow < rowSize and curCol < colSize and !hasZero) {
//                     for (int r = row; r <= curRow; ++r) {
//                         if (matrix[r][curCol] == '0') {
//                             hasZero = true;
//                             break;
//                         }
//                     }
                    
//                     for (int c = col; c <= curCol; ++c) {
//                         if (matrix[curRow][c] == '0') {
//                             hasZero = true;
//                             break;
//                         }
//                     }
                    
//                     if (!hasZero) {
//                         currSquareLength++;
//                     }
                    
//                     curRow++;
//                     curCol++;
//                 }
                
//                 maxSquareLength = max(maxSquareLength, currSquareLength);
//             }
//         }
        
//         int maxSquareArea = maxSquareLength * maxSquareLength;
//         return maxSquareArea;
//     }
};
