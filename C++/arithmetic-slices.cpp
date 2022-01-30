class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3)
            return 0;
        
        // dp stores number of arithmetic slices ending with nums[i]
        vector<int> dp(nums.size(), 0);
        dp[2] = nums[2] - nums[1] == nums[1] - nums[0] ? 1 : 0;
        
        // we need sum of all those slices ending with nums[i]
        int result = dp[2];
        
        for (int i = 3; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            }
            
            result += dp[i];
        }
        
        return result;
    }
};
