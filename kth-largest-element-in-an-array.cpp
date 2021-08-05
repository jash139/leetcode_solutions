class Solution {
public:
    int quickSelect(vector<int> &nums, int startIdx, int endIdx, int position) {
        while (true) {
            int pivotIdx = startIdx;
            int leftIdx = startIdx + 1;
            int rightIdx = endIdx;

            while (leftIdx <= rightIdx) {
                if (nums[leftIdx] > nums[pivotIdx] and nums[rightIdx] < nums[pivotIdx])
                    swap(nums[leftIdx], nums[rightIdx]);
                if (nums[leftIdx] <= nums[pivotIdx])
                    leftIdx++;
                if (nums[rightIdx] >= nums[pivotIdx])
                    rightIdx--;
            }
            swap(nums[pivotIdx], nums[rightIdx]);
            if (rightIdx == position)
                return nums[rightIdx];
            else if (rightIdx < position)
                startIdx = rightIdx + 1;
            else
                endIdx = rightIdx - 1;
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};
