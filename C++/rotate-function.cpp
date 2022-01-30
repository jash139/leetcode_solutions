class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int f0 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            f0 += nums[i] * i;
        }
        
        int maxSum = f0;
        
        int prev = f0;
        for (int i = 1; i < nums.size(); ++i) {
            int fi = prev - sum + nums[i - 1] * nums.size();
            maxSum = max(maxSum, fi);
            prev = fi;
        }
        
        return maxSum;
    }
};
