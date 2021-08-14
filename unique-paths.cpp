class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> numberOfWays(n + 1, vector<int>(m + 1, 0));
        
        for (int widthIdx = 1; widthIdx <= m; ++widthIdx) {
            for (int heightIdx = 1; heightIdx <= n; ++heightIdx) {
                if (widthIdx == 1 or heightIdx == 1)
                    numberOfWays[heightIdx][widthIdx] = 1;
                else {
                    int waysLeft = numberOfWays[heightIdx][widthIdx - 1];
                    int waysUp = numberOfWays[heightIdx - 1][widthIdx];
                    numberOfWays[heightIdx][widthIdx] = waysLeft + waysUp;
                }
            }
        }
        return numberOfWays[n][m];
    }
};
