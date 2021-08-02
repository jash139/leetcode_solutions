#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(n) Time | O(n) Space
    // n : length of nums
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        vector<int> maxAmount(nums.size(), 0);
        maxAmount[0] = nums[0];
        maxAmount[1] = max(nums[0], nums[1]);
        
        for (int idx = 2; idx < nums.size(); ++idx)
            maxAmount[idx] = max(maxAmount[idx - 1], maxAmount[idx - 2] + nums[idx]);
        
        return maxAmount[maxAmount.size() - 1];
    }
};
