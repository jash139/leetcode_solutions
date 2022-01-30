class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        
        int withFirstHouse = robHouseInRange(nums, 0, nums.size() - 1);
        int withoutFirstHouse = robHouseInRange(nums, 1, nums.size());
        return max(withFirstHouse, withoutFirstHouse);
    }
    
    int robHouseInRange(vector<int> &nums, int start, int end) {
        int prev = 0;
        int curr = 0;
        int maxAmount = 0;
        
        for (int i = start; i < end; ++i) {
            maxAmount = max(prev + nums[i], curr);
            prev = curr;
            curr = maxAmount;
        }
        
        return maxAmount;
    }
};
