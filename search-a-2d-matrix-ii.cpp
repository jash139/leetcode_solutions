class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;
        
        while (row < matrix.size() and col >= 0) {
            int curEle = matrix[row][col];
            if (curEle == target) 
                return true;
            if (curEle > target)
                col--;
            else
                row++;
        }
        
        return false;
    }
};
