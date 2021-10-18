class Solution {
public:
    int uniquePathsIII(vector<vector<int>> &grid) {
        vector<int> startIdx = getCellWithValue(grid, 1);
        int numEmptySquares = getEmptySquaresCount(grid);
        
        int numPaths = 0;
        
        getNumUniquePaths(grid, numEmptySquares, 0, numPaths, startIdx[0], startIdx[1]);
        
        return numPaths;
    }
    
    void getNumUniquePaths(vector<vector<int>> &grid, int numEmptySquares, int currEmptySquares, int &numPaths, int row, int col) {
        if (row >= grid.size() or col >= grid[0].size() or grid[row][col] == -1) {
            return;
        }
        
        if (grid[row][col] == 2) {
            if (currEmptySquares - 1 == numEmptySquares) {
                numPaths++;
            }
            return;
        }
        
        int prevValue = grid[row][col];
        grid[row][col] = -1;
        getNumUniquePaths(grid, numEmptySquares, currEmptySquares + 1, numPaths, row + 1, col);
        getNumUniquePaths(grid, numEmptySquares, currEmptySquares + 1, numPaths, row - 1, col);
        getNumUniquePaths(grid, numEmptySquares, currEmptySquares + 1, numPaths, row, col + 1);
        getNumUniquePaths(grid, numEmptySquares, currEmptySquares + 1, numPaths, row, col - 1);
            
        grid[row][col] = prevValue;
    }
    
    vector<int> getCellWithValue(vector<vector<int>> &grid, int searchValue) {
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == searchValue) {
                    return vector<int>{row, col};
                }
            }
        }
        return vector<int>{0, 0};
    }
    
    int getEmptySquaresCount(vector<vector<int>> &grid) {
        int count = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 0)
                    count++;
            }
        }
        return count;
    }
};
