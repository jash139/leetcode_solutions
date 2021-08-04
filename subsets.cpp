class Solution {
public:
    // O(n * 2^n) Time | O(n * 2^n) Space
    // n : length of input array
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets = {{}};
        
        for (int idx = 0; idx < nums.size(); ++idx) {
            int element = nums[idx];
            int subsetLength = subsets.size();
            
            for (int j = 0; j < subsetLength; ++j) {
                vector<int> newSubset = subsets[j];
                newSubset.push_back(element);
                subsets.push_back(newSubset);
            }
        }
        
        return subsets;
    }
};
