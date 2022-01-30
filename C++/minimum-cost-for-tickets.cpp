class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travelDays;
        for (int day : days) {
            travelDays.insert(day);
        }
        vector<int> minCost(366, 0);
        for (int i = 1; i < 366; ++i) {
            minCost[i] = minCost[i - 1];
            
            if (travelDays.find(i) != travelDays.end()) {
                minCost[i] = min({minCost[i - 1] + costs[0],
                                  minCost[max(0, i - 7)] + costs[1],
                                  minCost[max(0, i - 30)] + costs[2]});
            }
        }
        return minCost[365];
    }
};
