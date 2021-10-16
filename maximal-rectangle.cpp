class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 or matrix[0].size() == 0) {
            return 0;
        }
        
        vector<int> heights(matrix[0].size() + 1, 0);
        int maxRectangleArea = 0;
        
        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 0; col < matrix[0].size(); ++col) {
                if (matrix[row][col] == '0') {
                    heights[col] = 0;
                } else {
                    heights[col]++;
                }
            }
            int currentArea = getMaxAreaFromHeights(heights);
            maxRectangleArea = max(maxRectangleArea, currentArea);
        }
            
        return maxRectangleArea;
    }
    
    int getMaxAreaFromHeights(vector<int> heights) {
        int maxArea = 0;
        stack<int> st;
        for (int i = 0; i < heights.size(); ++i) {
            if (st.empty() or heights[i] >= heights[st.top()]) {
                st.push(i);
            } else {
                int currHeight = heights[st.top()];
                st.pop();
                int currWidth = st.empty() ? i : i - st.top() - 1;
                int currArea = currHeight * currWidth;
                maxArea = max(maxArea, currArea);
                i--;
            }
        }
        
        return maxArea;
    }
};
