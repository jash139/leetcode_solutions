class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxes(height.size(), 0);
        int waterContained = 0;
        
        int leftMax = 0;
        for (int idx = 0; idx < height.size(); ++idx) {
            int curHeight = height[idx];
            maxes[idx] = leftMax;
            leftMax = max(leftMax, curHeight);
        }
        
        int rightMax = 0;
        for (int idx = height.size() - 1; idx >= 0; --idx) {
            int curHeight = height[idx];
            int minHeight = min(maxes[idx], rightMax);
            maxes[idx] = curHeight < minHeight ? minHeight - curHeight : 0;
            rightMax = max(rightMax, curHeight);
        }
        
        for (int idx = 0; idx < maxes.size(); ++idx)
            waterContained += maxes[idx];
        return waterContained;
    }
};
