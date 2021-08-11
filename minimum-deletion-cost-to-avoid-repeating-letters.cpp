class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int deletionCost = 0;
        
        int i = 1;
        
        while (i < s.size()) {
            int maxCost = INT_MIN;
            int totalCost = 0;
            while (s[i - 1] == s[i]) {
                totalCost += cost[i - 1];
                maxCost = max(maxCost, max(cost[i], cost[i - 1]));
                i++;
            }
            if (maxCost != INT_MIN) {
                totalCost += cost[i - 1];
                deletionCost += totalCost - maxCost;
                i--;
            }
            i++;
        }
        
        return deletionCost;
    }
};
