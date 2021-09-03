class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = prices[0];
        
        for (int i = 1; i < prices.size(); ++i) {
            int curProfit = prices[i] - minPrice;
            maxProfit = max(maxProfit, curProfit);
            minPrice = min(minPrice, prices[i]);
        }
        
        return maxProfit;
        
//         int minPrice = INT_MAX, profit = 0, n = prices.size();
//         for(int i = 0; i < n; ++i) {
//             if (prices[i] < minPrice) {
//                 minPrice = prices[i];
//             } else {
//                 profit = max(profit, prices[i] - minPrice);
//             }
//         }
        
//         return profit;   
    }
};
