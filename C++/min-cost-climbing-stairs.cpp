class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> minCost(cost.size(), 0);
        minCost[0] = cost[0];
        minCost[1] = cost[1];
        
        for (int i = 2; i < cost.size(); ++i) {
            minCost[i] = cost[i] + min(minCost[i - 1], minCost[i - 2]);
        }
        
        return min(minCost[cost.size() - 2], minCost[cost.size() - 1]);
    }
    
------------------------------------------------------------------------------
    
//    O(1) Space
    int minCostClimbingStairs(vector<int>& cost) {
        int first = cost[0];
        int second = cost[1];
        
        for (int i = 2; i < cost.size(); ++i) {
            int currCost = cost[i] + min(first, second);
            first = second;
            second = currCost;
        }
        
        return min(first, second);
    }
};
