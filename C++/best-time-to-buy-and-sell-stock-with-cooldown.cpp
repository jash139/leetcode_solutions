class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 1) {
            return 0;
        }
        
        vector<int> maxProfitEndingWithBuy(prices.size() + 1, 0);
        vector<int> maxProfitEndingWithSell(prices.size() + 1, 0);
        
        maxProfitEndingWithBuy[1] = -prices[0];
        
        for (int i = 2; i < prices.size() + 1; ++i) {
            int currPrice = prices[i - 1];
            maxProfitEndingWithBuy[i] = max(maxProfitEndingWithBuy[i - 1], maxProfitEndingWithSell[i - 2] - currPrice);
            maxProfitEndingWithSell[i] = max(maxProfitEndingWithSell[i - 1], maxProfitEndingWithBuy[i - 1] + currPrice);
        }
        
        return maxProfitEndingWithSell[prices.size()];
    }
};
