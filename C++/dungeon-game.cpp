class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        vector<vector<int>> dp(dungeon.size() + 1, vector<int>(dungeon[0].size() + 1, INT_MAX));
        
        dp[dungeon.size()][dungeon[0].size() - 1] = 1;
        dp[dungeon.size() - 1][dungeon[0].size()] = 1;
        
        for (int row = dungeon.size() - 1; row >= 0; --row) {
            for (int col = dungeon[0].size() - 1; col >= 0; --col) {
                int requiredHealth = min(dp[row + 1][col], dp[row][col + 1]) - dungeon[row][col];
                dp[row][col] = requiredHealth <= 0 ? 1 : requiredHealth;
            }
        }
        
        return dp[0][0];
    }
};



-----------------------------------------------------------------------------------



class Solution {
public:
     int getMinimumHealth(vector<vector<int>> &dungeon, int row, int col, vector<vector<int>> &memo) {
         if (row >= dungeon.size() or col >= dungeon[0].size()) {
             return INT_MAX;
         }
         
         if (row == dungeon.size() - 1 and col == dungeon[0].size() - 1) {
             return dungeon[row][col] <= 0 ? -dungeon[row][col] + 1 : 1;
         }
         
         if (memo[row][col] != INT_MAX) {
             return memo[row][col];
         }
         
         int valueRight = getMinimumHealth(dungeon, row, col + 1, memo);
         int valueDown = getMinimumHealth(dungeon, row + 1, col, memo);
         
         int minHealthReq = min(valueRight, valueDown) - dungeon[row][col];
         memo[row][col] = minHealthReq <= 0 ? 1 : minHealthReq;
         return memo[row][col];
     }
    
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        vector<vector<int>> memo(dungeon.size(), vector<int>(dungeon[0].size(), INT_MAX));
        return getMinimumHealth(dungeon, 0, 0, memo);
    }
};
