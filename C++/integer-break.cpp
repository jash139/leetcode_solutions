class Solution {
public:
    int integerBreak(int n) {
        vector<int> products(n + 1, 0);
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i / 2; ++j) {
                products[i] = max(products[i], max(j, products[j]) * max(i - j, products[i - j]));
            }
        }
            
        return products[n];
    }
};
