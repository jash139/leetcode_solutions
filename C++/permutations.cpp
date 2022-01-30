class Solution {
public:
    void getAllPermutations(vector<vector<int>> &ans, vector<int> &nums, int start, int end) {
        if (start == end) {
            ans.push_back(nums);
            return;
        }
        
        for (int i = start; i <= end; ++i) {
            swap(nums[start], nums[i]);
            getAllPermutations(ans, nums, start + 1, end);
            swap(nums[start], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getAllPermutations(ans, nums, 0, nums.size() - 1);
        return ans;
    }
};
