class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 or numRows >= s.length()) return s;
        int curRow = 0;
        vector<vector<char>> matrix(numRows, vector<char>());
        
        int step = -1;
        for (char ch : s) {
            matrix[curRow].push_back(ch);
            
            if (curRow == 0 or curRow == numRows - 1)
                step *= -1;
            
            curRow += step;
        }
        
        string result = "";
        
        for (auto row : matrix)
            result += string(row.begin(), row.end());
        
        return result;
    }
};
