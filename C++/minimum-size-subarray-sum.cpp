class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        
        int currSum = 0;
        int minLen = INT_MAX;
        
        for (int i = 0; i < nums.size(); ++i) {
            currSum += nums[i];
            
            while (currSum >= target) {
                minLen = min(minLen, i - left + 1);
                currSum -= nums[left++];
            }
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
};
