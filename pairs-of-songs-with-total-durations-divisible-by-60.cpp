class Solution {
public:
    int getPairs(int n) {
        return (n * (n - 1)) / 2;
    }
    
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> remainders(60, 0);
        
        for (auto t : time) {
            remainders[t % 60]++;
        }
        
        int totalPairs = 0;
        
        totalPairs += getPairs(remainders[0]);
        totalPairs += getPairs(remainders[30]);
        
        for (int i = 1; i <= 29; ++i) {
            totalPairs += remainders[i] * remainders[60 - i];
        }
        
        return totalPairs;
    }
};
