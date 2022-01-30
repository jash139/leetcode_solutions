class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int best = INT_MIN;
        
        for (int idx = 0; idx < nums.size(); ++idx) {
            sum = max(sum + nums[idx], nums[idx]);
            best = max(best, sum);
        }
        
        return best;
    }
};
