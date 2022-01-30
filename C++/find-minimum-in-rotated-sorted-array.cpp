class Solution {
public:
    // O(log(n)) Time | O(1) Space
    // n : number of elements in the input array
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            if (nums[left] < nums[right]) {
                return nums[left];
            }
            
            int mid = (left + right) / 2;
            
            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return nums[left];
    }
};
