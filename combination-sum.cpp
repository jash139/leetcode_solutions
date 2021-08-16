class Solution {
public:
    void getAllCombinations(vector<vector<int>> &allCombinations, vector<int> &combination, int runningSum, vector<int> candidates, int target, int startIdx) {
        if (runningSum > target)
            return;
        
        if (runningSum == target) {
            allCombinations.push_back(combination);
            return;
        }
        
        for (int i = startIdx; i < candidates.size(); ++i) {
            combination.push_back(candidates[i]);
            runningSum += candidates[i];
            getAllCombinations(allCombinations, combination, runningSum, candidates, target, i);
            combination.pop_back();
            runningSum -= candidates[i];
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int runningSum = 0;
        vector<vector<int>> allCombinations;
        vector<int> combination;
        getAllCombinations(allCombinations, combination, runningSum, candidates, target, 0);
        
        return allCombinations;
    }
};
