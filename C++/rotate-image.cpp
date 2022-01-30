class Solution {
public:
    // Rotate == transpose + relfect
    void transpose(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
    
    void reflect(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n / 2; ++j)
                swap(matrix[i][j], matrix[i][n - j - 1]);
    }
    
    // Transpose + reflect = rotate by 90 deg clockwise
    void rotate(vector<vector<int>> &matrix) {
        transpose(matrix);
        reflect(matrix);
    }
    
    // Rotate groups of four cells
    // void rotate(vector<vector<int>> &matrix) {
    //     int n = matrix.size();
    //     for (int i = 0; i < (n + 1) / 2; ++i) {
    //         for (int j = 0; j < n / 2; ++j) {
    //             int temp = matrix[n - 1 - j][i];
    //             matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
    //             matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
    //             matrix[j][n - 1 - i] = matrix[i][j];
    //             matrix[i][j] = temp;
    //         }
    //     }
    // }
};
