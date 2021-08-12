class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allSubsets = {{}};
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();) {
            int count = 0;
            while (i + count < nums.size() and nums[count + i] == nums[i])
                count++;
            int len = allSubsets.size();
            for (int j = 0; j < len; ++j) {
                vector<int> subset = allSubsets[j];
                for (int k = 0; k < count; ++k) {
                    subset.push_back(nums[i]);
                    allSubsets.push_back(subset);
                }
            }
            i += count;
        }
        
        return allSubsets;
    }
};
