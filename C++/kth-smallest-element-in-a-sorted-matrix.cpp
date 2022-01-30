class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = matrix[0][0];
        int high = matrix[m - 1][n - 1];
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            int count = 0; 
            int j = n - 1;
            
            // matrix is sorted both row and column wise
            // so no need to reset j to (n - 1) after
            // each row traversal, as all elements below
            // would be greater than mid
            for (int i = 0; i < m; i++) {
                while (j >= 0 and matrix[i][j] > mid)
                    j--;
                count += j + 1;
            }
            
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
