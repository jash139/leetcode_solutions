class Solution {
public:
    void getCombinations(vector<vector<int>> &allCombinations, vector<int> &combination, int start, int n, int k) {
        if (k == 0) {
            allCombinations.push_back(combination);
            return;
        }
        
        for (int i = start; i <= n; ++i) {
            combination.push_back(i);
            getCombinations(allCombinations, combination, i + 1, n, k - 1);
            combination.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> allCombinations;
        vector<int> combination;
        getCombinations(allCombinations, combination, 1, n, k);
        return allCombinations;
    }
};
