class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        
        for (int idx = 3; idx <= n; ++idx)
            dp[idx] = dp[idx - 1] + dp[idx - 2];
        
        return dp[n];
    }
    
    
//     vector<int> memo;
//     Solution(): memo(50, -1) {}
    
//     int climbStairs(int n) {
//         if (memo[n] >= 0) return memo[n];
//         if (n == 1) return 1;
//         if (n == 2) return 2;
        
//         int steps = climbStairs(n - 1) + climbStairs(n - 2);
//         memo[n] = steps;
//         return steps;
//     }
};
