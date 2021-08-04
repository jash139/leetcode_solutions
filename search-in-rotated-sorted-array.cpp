class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int middle = left + (right - left) / 2;
            int potentialMatch = nums[middle];
            int leftNum = nums[left];
            int rightNum = nums[right];
            if (potentialMatch == target)
                return middle;
            else if (leftNum <= potentialMatch) {
                if (target >= leftNum and target < potentialMatch)
                    right = middle - 1;
                else
                    left = middle + 1;
            } else {
                if (target <= rightNum and target > potentialMatch)
                    left = middle + 1;
                else
                    right = middle - 1;
            }
        }
        return -1;
    }
};
