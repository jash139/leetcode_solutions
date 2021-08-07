class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> numOfCoins(amount + 1, INT_MAX);
        numOfCoins[0] = 0;
        
        for (int coin : coins) {
            for (int j = coin; j < numOfCoins.size(); ++j) {
                int toCompare = 0;
                if (numOfCoins[j - coin] == INT_MAX)
                    toCompare = INT_MAX;
                else
                    toCompare = 1 + numOfCoins[j - coin];
                numOfCoins[j] = min(numOfCoins[j], toCompare);
            }
        }
        return numOfCoins[amount] == INT_MAX ? -1 : numOfCoins[amount];
    }
};
