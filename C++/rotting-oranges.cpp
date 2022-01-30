class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshOranges = 0;
        queue<vector<int>> q;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1)
                    freshOranges++;
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        int numOfMins = -1;
        
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                vector<int> idxs = q.front();
                q.pop();
                int row = idxs[0];
                int col = idxs[1];
                
                if (row + 1 < grid.size() and grid[row + 1][col] == 1) {
                    grid[row + 1][col] = 2;
                    q.push({row + 1, col});
                    freshOranges--;
                }
                if (row - 1 >= 0 and grid[row - 1][col] == 1) {
                    grid[row - 1][col] = 2;
                    q.push({row - 1, col});
                    freshOranges--;
                }
                if (col + 1 < grid[0].size() and grid[row][col + 1] == 1) {
                    grid[row][col + 1] = 2;
                    q.push({row, col + 1});
                    freshOranges--;
                }
                if (col - 1 >= 0 and grid[row][col - 1] == 1) {
                    grid[row][col - 1] = 2;
                    q.push({row, col - 1});
                    freshOranges--;
                }
            }
            numOfMins++;
        }
        
        
        if (freshOranges > 0) return -1;
        if (numOfMins == -1) return 0;
        
        return numOfMins;
    }
};
