class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> leftMax(nums.size(), INT_MIN);
        vector<int> rightMax(nums.size(), INT_MIN);

        leftMax[0] = nums[0];
        rightMax[nums.size() - 1] = nums[nums.size() - 1];

        for (int i = 1; i < nums.size(); i++) {
            leftMax[i] = (i % k == 0) ? nums[i] : max(leftMax[i - 1], nums[i]);

            int j = nums.size() - i - 1;
            rightMax[j] = (j % k == 0) ? nums[j] : max(rightMax[j + 1], nums[j]);
        }

        vector<int> slidingMax(nums.size() - k + 1);
        for (int i = 0, j = 0; i + k <= nums.size(); i++) {
            slidingMax[j++] = max(rightMax[i], leftMax[i + k - 1]);
        }

        return slidingMax;
    }
};
