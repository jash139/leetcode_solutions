class Solution {
public:
    // O(log(min(m, n))) Time | O(1) Space
    // m : length of first array
    // n : length of second array
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int size1 = nums1.size();
        int size2 = nums2.size();
        
        int low = 0;
        int high = nums1.size();
        
        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (size1 + size2 + 1) / 2 - partitionX;
            
            int maxLeftX = partitionX == 0 ? INT_MIN : nums1[partitionX - 1];
            int minRightX = partitionX == size1 ? INT_MAX : nums1[partitionX];

            int maxLeftY = partitionY == 0 ? INT_MIN : nums2[partitionY - 1];
            int minRightY = partitionY == size2 ? INT_MAX : nums2[partitionY];
            
            if (maxLeftX <= minRightY and maxLeftY <= minRightX) {
                if ((size1 + size2) % 2 == 0) {
                    return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
                } else {
                    return (double)(max(maxLeftX, maxLeftY));
                }
            } else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } else {
                low = partitionX + 1;
            }
        }
        
        return -1;
    }
};
