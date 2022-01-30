class Solution {
public:
    int fib(int n) {
        vector<int> memo = {0, 1};
        
        for (int i = 2; i <= n; ++i) {
            memo.push_back(memo[i - 1] + memo[i - 2]);
        }
            
        return memo[n];
    }
};



------------------------------------------------------------



class Solution {
    vector<int> memo;
public:
    Solution(): memo(31, -1) {}
    int fib(int n) {
        if (memo[n] > -1) return memo[n];
        if (n <= 1) return n;
        
        return fib(n - 1) + fib(n - 2);
    }
};
