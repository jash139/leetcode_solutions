#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(n) Time | O(1) Space
    // n : length of input array
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int idx = 0; idx < nums.size(); ++idx)
            totalSum += nums[idx];
        
        int leftSum = 0;
        int rightSum = totalSum;
        
        int idx = 0;
        while (idx < nums.size()) {
            rightSum -= nums[idx];
            
            if (leftSum == rightSum)
                return idx;
            
            leftSum += nums[idx]; 
            idx++;
        }
        
        return -1;
    }
};
