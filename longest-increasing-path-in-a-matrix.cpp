class Solution {
public:
    int dfs(vector<vector<int>> &lengthHere, vector<vector<int>> &matrix, int row, int col, int prev) {
        if (row < 0 or col < 0 or row >= matrix.size() or col >= matrix[0].size() or matrix[row][col] <= prev) {
            return 0;
        }
        
        if (lengthHere[row][col]) {
            return lengthHere[row][col];
        }
        
        int up = dfs(lengthHere, matrix, row - 1, col, matrix[row][col]);
        int down = dfs(lengthHere, matrix, row + 1, col, matrix[row][col]);
        int left = dfs(lengthHere, matrix, row, col - 1, matrix[row][col]);
        int right = dfs(lengthHere, matrix, row, col + 1, matrix[row][col]);
        
        lengthHere[row][col] = max({up, down, left, right}) + 1;
        return lengthHere[row][col];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> lengthHere(201, vector<int>(201, 0));
        int maxLen = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                int curLen = dfs(lengthHere, matrix, i, j, -1);
                maxLen = max(maxLen, curLen);
            }
        }
        return maxLen;
    }
};
