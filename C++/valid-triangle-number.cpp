class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int tripletCount = 0;
        
        for (int right = 2; right < len; ++right) {
            int left = 0;
            int mid = right - 1;
            
            while (left < mid) {
                if (nums[left] + nums[mid] > nums[right]) {
                    tripletCount += mid - left;
                    mid--;
                } else {
                    left++;
                }
            }
        }
        
        return tripletCount;
    }
};
