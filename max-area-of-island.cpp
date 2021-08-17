class Solution {
public:
    int getIslandArea(vector<vector<int>> &grid, int row, int col) {
        if (row < 0 or col < 0 or row >= grid.size() or col >= grid[0].size() or grid[row][col] != 1) {
            return 0;
        }
        
        grid[row][col] = 2;
        int topValue = getIslandArea(grid, row - 1, col);
        int downValue = getIslandArea(grid, row + 1, col);
        int leftValue = getIslandArea(grid, row, col - 1);
        int rightValue = getIslandArea(grid, row, col + 1);
        
        return 1 + topValue + downValue + leftValue + rightValue;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                int curArea = getIslandArea(grid, row, col);
                maxArea = max(maxArea, curArea);
            }
        }
        
        return maxArea;
    }
};
