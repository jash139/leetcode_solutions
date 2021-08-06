class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        
        int prev1 = 0, cur1 = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            int temp = prev1;
            prev1 = cur1;
            cur1 = max(temp + nums[i], cur1);
        }
        
        int prev2 = 0, cur2 = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int temp = prev2;
            prev2 = cur2;
            cur2 = max(temp + nums[i], cur2);
        }
        
        return max(cur1, cur2);
    }
};
