class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        
        int height = mat.size() - 1;
        int width = mat[0].size() - 1;
        int row = 0;
        int col = 0;
        bool goingDown = false;
        
        while (!isOutOfBounds(row, col, height, width)) {
            result.push_back(mat[row][col]);
            
            if (goingDown) {
                if (col == 0 or row == height) {
                    goingDown = false;
                    
                    if (row == height) {
                        col++;
                    } else {
                        row++;
                    }
                } else {
                    col--;
                    row++;
                }
            } else {
                if (row == 0 or col == width) {
                    goingDown = true;
                    
                    if (col == width) {
                        row++;
                    } else {
                        col++;
                    }
                } else {
                    col++;
                    row--;
                }
            }
        }
        
        return result;
    }
    
    bool isOutOfBounds(int row, int col, int height, int width) {
        return row < 0 or col < 0 or row > height or col > width;
    }
};
