class Solution {
public:
    // O(n) Time | O(1) Space
    // n : length of input array
    bool checkPossibility(vector<int>& nums) {
        int modified = 0;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < prev and modified++) return false;
            if (nums[i] < prev and i - 2 >= 0 && nums[i - 2] > nums[i]) continue;
            prev = nums[i];
        }
        return true;
    }
};
