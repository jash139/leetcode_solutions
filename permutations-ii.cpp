class Solution {
public:
    void getPermutations(vector<int> nums, int start, vector<vector<int>> &permutations) {
        if (start == nums.size()) {
            permutations.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); ++i) {
            if (i == start or nums[start] != nums[i]) {
                swap(nums[i], nums[start]);
                getPermutations(nums, start + 1, permutations);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;
        
        sort(nums.begin(), nums.end());
        getPermutations(nums, 0, permutations);
        
        return permutations;
    }
};
