class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int missingNum = 1;
        for (int idx = 0; idx < nums.size(); ++idx) {
            if (nums[idx] <= 0 or nums[idx] > nums.size() or nums[idx] == idx + 1 or nums[nums[idx] - 1] == nums[idx])
                continue;
            
            swap(nums[nums[idx] - 1], nums[idx]);
            idx--;
        }
        
        for (int idx = 0; idx < nums.size(); ++idx) {
            if (nums[idx] != idx + 1) {
                return idx + 1;
            }
        }
        
        return nums.size() + 1;
    }
};
