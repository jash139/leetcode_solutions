class Solution {
public:
    int getLowerBound(vector<int> nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return left;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = getLowerBound(nums, target);
        int idx2 = getLowerBound(nums, target + 1) - 1;
        
        if (idx1 < nums.size() and nums[idx1] == target) 
            return vector<int> {idx1, idx2};
        else
            return vector<int> {-1, -1};
    }
};
