class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        
        vector<int> maxPossible(nums.size(), 0);
        maxPossible[0] = nums[0];
        maxPossible[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < nums.size(); ++i) {
            maxPossible[i] = max(nums[i] + maxPossible[i - 2], maxPossible[i - 1]);
        }
        
        return maxPossible[nums.size() - 1];
    }
    
------------------------------------------------------------------------------
    
    // O(1) Space
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        
        int prev = nums[0];
        int curr = max(nums[0], nums[1]);
        
        for (int i = 2; i < nums.size(); ++i) {
            int currAmount = max(nums[i] + prev, curr);
            prev = curr;
            curr = currAmount;
        }
        
        return curr;
    }
};
