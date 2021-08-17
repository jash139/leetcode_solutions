class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSums = {{0, 1}};
        
        int count = 0;
        int runningSum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            runningSum += nums[i];
            int remainder = runningSum % k;
            if (remainder < 0) {
                remainder += k; // since -1 mod 5 and 4 mod 5 are equivalent
            }
            if (prefixSums.find(remainder) != prefixSums.end()) {
                count += prefixSums[remainder];
            }
            prefixSums[remainder]++;
        }
        
        return count;
    }
};
