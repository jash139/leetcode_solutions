class Solution {
public:
    bool canJump(vector<int>& nums) {
        int stepsRemaining = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            stepsRemaining--;
            if (stepsRemaining < 0) {
                return false;
            }
            
            if (stepsRemaining < nums[i]) {
                stepsRemaining = nums[i];
            }
        }
        return true;
    }
};
