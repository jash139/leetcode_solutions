class Solution {
public:
    vector<int> buildPattern(string substr) {
        vector<int> pattern(substr.length(), - 1);
        
        int j = 0;
        int i = 1;
        
        while (i < substr.length()) {
            if (substr[i] == substr[j]) {
                pattern[i] = j;
                i++;
                j++;
            } else if (j > 0) {
                j = pattern[j - 1] + 1;
            } else {
                i++;
            }
        }
        
        return pattern;
    }
    
    int doesMatch(string str, string substr, vector<int> pattern) {
        int i = 0;
        int j = 0;
        
        while (i + substr.length() - j <= str.length()) {
            if (str[i] == substr[j]) {
                if (j == substr.length() - 1) {
                    return i - substr.length() + 1;
                }
                i++;
                j++;
            } else if (j > 0) {
                j = pattern[j - 1] + 1;
            } else {
                i++;
            }
        }
        
        return -1;
    }
    
    // KMP Algorithm
    int strStr(string str, string substr) {
        if (str.length() == 0 and substr.length() == 0) return 0;
        else if (substr.length() == 0) return 0;
        vector<int> pattern = buildPattern(substr);
        return doesMatch(str, substr, pattern);
    }
};
