class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            int minSquares = INT_MAX;
            for (int j = 1; j * j <= i; ++j)
                minSquares = min(minSquares, dp[i - j * j] + 1);
            dp[i] = minSquares;
        }
        return dp[n];
    }
};
