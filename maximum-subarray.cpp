#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = INT_MIN;
        int sum = 0;
        
        for (int idx = 0; idx < nums.size(); ++idx) {
            sum = max(nums[idx], sum + nums[idx]);
            best = max(sum, best);
        }
        
        return best;
            
            
        // int best = INT_MIN, sum = 0, n = nums.size();
        // int maximum = INT_MIN;
        // for(int i = 0; i < n; ++i) {
        //     if (nums[i] >= maximum) {
        //         maximum = nums[i];
        //     }
        //     sum = max(nums[i], sum + nums[i]);
        //     best = max(sum, best);
        // }
        // return max(maximum, best);
    }
};
