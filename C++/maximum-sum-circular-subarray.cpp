class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = nums[0];
        int minSum = nums[0];
        
        int currMax = 0;
        int currMin = 0;
        
        for (int n : nums) {
            currMax = max(n + currMax, n);
            maxSum = max(maxSum, currMax);
            
            currMin = min(n + currMin, n);
            minSum = min(minSum, currMin);
            
            totalSum += n;
        }
        
        return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
    }
};
