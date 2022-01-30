class Solution {
public:
    // O(nm) Time | O(1) Space
    // n and m are height and width of grid
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1)
            return 0;
        
        obstacleGrid[0][0] = 1;
        for (int col = 1; col < obstacleGrid[0].size(); ++col) {
            if (obstacleGrid[0][col] == 1) {
                obstacleGrid[0][col] = 0;
            } else {
                obstacleGrid[0][col] = obstacleGrid[0][col - 1];
            }       
        }
        
        for (int row = 1; row < obstacleGrid.size(); ++row) {
            if (obstacleGrid[row][0] == 1) {
                obstacleGrid[row][0] = 0;
            } else {
                obstacleGrid[row][0] = obstacleGrid[row - 1][0];
            }       
        }
        
        for (int row = 1; row < obstacleGrid.size(); ++row) {
            for (int col = 1; col < obstacleGrid[0].size(); ++col) {
                if (obstacleGrid[row][col] == 1) {
                    obstacleGrid[row][col] = 0;
                } else {
                    obstacleGrid[row][col] = obstacleGrid[row - 1][col] + obstacleGrid[row][col - 1];
                }
            }
        }
        
        return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
