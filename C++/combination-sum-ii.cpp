class Solution {
public:
    void getCombinations(vector<vector<int>> &result, vector<int> candidates, vector<int> tempComb, int start, int target) {
        if (target == 0) {
            result.push_back(tempComb);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target)
                return;
            if (i != 0 and candidates[i - 1] == candidates[i] and i > start)
                continue;
            tempComb.push_back(candidates[i]);
            getCombinations(result, candidates, tempComb, i + 1, target - candidates[i]);
            tempComb.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        
        sort(candidates.begin(), candidates.end());
        vector<int> tempComb = {};
        getCombinations(result, candidates, tempComb, 0, target);
        
        return result;
    }
};
