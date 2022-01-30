class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long int columnNumber = 0;
        long long int multiplier = 1;
        int idx = columnTitle.size() - 1;
        while (idx >= 0) {
            char ch = columnTitle[idx];
            columnNumber += multiplier * (int)(ch - 65 + 1);
            multiplier *= 26;
            idx--;
        }
        
        return columnNumber;
    }
};
