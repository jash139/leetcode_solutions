class Solution {
public:
    // O(n) Time | O(1) Space
    // n : length of input array
    int maxArea(vector<int>& height) {
        int maxCapacity = INT_MIN;
        
        int leftIdx = 0;
        int rightIdx = height.size() - 1;
        
        while (leftIdx < rightIdx) {
            int minHeight = min(height[leftIdx], height[rightIdx]);
            int width = rightIdx - leftIdx;
            int curCapacity = minHeight * width;
            
            if (curCapacity > maxCapacity)
                maxCapacity = curCapacity;
            
            if (height[leftIdx] < height[rightIdx])
                leftIdx++;
            else
                rightIdx--;
        }
        
        return maxCapacity;
    }
};
