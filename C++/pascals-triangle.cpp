class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return vector<vector<int>>{{1}};
        
        vector<vector<int>> triangle;
        triangle.push_back({1});
        triangle.push_back({1, 1});
        
        for (int i = 2; i < numRows; ++i) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};
