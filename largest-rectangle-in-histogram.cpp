class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> pillarIndices;
        heights.push_back(0);
        int maxArea = 0;
        for (int idx = 0; idx < heights.size(); ++idx) {
            int height = heights[idx];
            
            while (!pillarIndices.empty() and heights[pillarIndices.top()] >= height) {
                int pillarHeight = heights[pillarIndices.top()];
                pillarIndices.pop();
                
                int width = pillarIndices.empty() ? idx : idx - pillarIndices.top() - 1;
                maxArea = max(maxArea, width * pillarHeight);
            }
            
            pillarIndices.push(idx);
        }
        return maxArea;
    }
};
