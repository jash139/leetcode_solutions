class Solution {
public:
    int findWaysToTarget(vector<int> nums, int currIdx, int currSum, vector<unordered_map<int, int>> &ways) {
        if (currIdx == nums.size()) {
            bool isEqualToTarget = currSum == 0;
            return isEqualToTarget;
        }
        
        if (ways[currIdx].find(currSum) != ways[currIdx].end()) {
            return ways[currIdx][currSum];
        }
        
        int valueWithCurAdded = findWaysToTarget(nums, currIdx + 1, currSum + nums[currIdx], ways);
        int valueWithCurSubtracted = findWaysToTarget(nums, currIdx + 1, currSum - nums[currIdx], ways);
        
        ways[currIdx][currSum] = valueWithCurAdded + valueWithCurSubtracted;
        
        return ways[currIdx][currSum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> ways(nums.size());
        
        return findWaysToTarget(nums, 0, target, ways);
    }
    
//     // O(2 ^ n) Time | O(n) Space
//     // n : length of the array
//     void findWaysToTarget(vector<int> nums, int currIdx, int target, int runningSum, int &waysToTarget) {
//         if (currIdx == nums.size()) {
//             if (runningSum == target)
//                 waysToTarget++;
//             return;
//         }
        
//         findWaysToTarget(nums, currIdx + 1, target, runningSum + nums[currIdx], waysToTarget);
//         findWaysToTarget(nums, currIdx + 1, target, runningSum - nums[currIdx], waysToTarget);
//     }
    
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int waysToTarget = 0;
        
//         findWaysToTarget(nums, 0, target, 0, waysToTarget);
        
//         return waysToTarget;
//     }
};
