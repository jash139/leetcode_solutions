class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        vector<int> maxPoints(10000, 0);
        for (int n : nums) {
            maxPoints[n] += n;
        }
        
        for (int i = 2; i < maxPoints.size(); ++i) {
            maxPoints[i] = max(maxPoints[i - 2] + maxPoints[i], maxPoints[i - 1]);
        }
            
        return maxPoints[maxPoints.size() - 1];
    }
};
