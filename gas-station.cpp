class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startCityIdx = 0;
        int milesAtStartCity = 0;
        int milesRemaining = 0;
        
        for (int i = 1; i < gas.size(); ++i) {
            milesRemaining += gas[i - 1] - cost[i - 1];
            if (milesRemaining < milesAtStartCity) {
                milesAtStartCity = milesRemaining;
                startCityIdx = i;
            }
        }
        
        milesRemaining += gas[gas.size() - 1] - cost[cost.size() - 1];
        
        return milesRemaining >= 0 ? startCityIdx : -1;
    }
};
