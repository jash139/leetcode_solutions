class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        
        int idx = nums.size() - 2;
        
        while (idx >= 0) {
            if (nums[idx] < nums[idx + 1]) {
                break;
            }
            idx--;
        }
        
        if (idx < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            int l = nums.size() - 1;
            while (l >= 0) {
                if (nums[l] > nums[idx]) {
                    break;
                }
                l--;
            }
            swap(nums[idx], nums[l]);
            reverse(nums.begin() + idx + 1, nums.end());
        }
    }
};
