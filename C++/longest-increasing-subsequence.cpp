class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lengths(nums.size(), 1);
        int maxLengthIdx = 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            int curNum = nums[i];
            for (int j = 0; j < i; ++j) {
                int otherNum = nums[j];
                if (otherNum < curNum)
                    lengths[i] = max(lengths[i], lengths[j] + 1);
            }
            if (lengths[i] > lengths[maxLengthIdx])
                maxLengthIdx = i;
        }
        
        return lengths[maxLengthIdx];
    }
};
