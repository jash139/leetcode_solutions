class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSums = {{0, 1}};
        
        int count = 0;
        int runningSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            runningSum += nums[i];
            int diff = runningSum - k;
            if (prefixSums.find(diff) != prefixSums.end()) {
                count += prefixSums[diff];
            }
            prefixSums[runningSum]++;
        }
        
        return count;
    }
};
