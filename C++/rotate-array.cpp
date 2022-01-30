class Solution {
public:
    // Using reverse
    // Reverse whole array
    // Reverse first k numbers
    // Reverse last n - k numbers
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
    
    // Using extra space
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k = k % n;
//         int idx = 0;
//         vector<int> numsCopy = nums;
        
//         for (int i = 0; i < n; ++i) {
//             int pos = (i + k) % n;
//             nums[pos] = numsCopy[idx++];
//         }
//     }
};
