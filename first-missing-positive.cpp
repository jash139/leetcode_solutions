class Solution {
public:
    // Put numbers which are within 0 and nums.size()
    // in their correct position
    // In second iteration check first number which is
    // not in its correct position
    // That is the smallest missing positive number
    
    int firstMissingPositive(vector<int>& nums) {
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
