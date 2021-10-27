class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }
        vector<vector<int>> cache(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return areInterwoven(s1, s2, s3, 0, 0, cache);
    }
    
    bool areInterwoven(string s1, string s2, string s3, int i, int j, vector<vector<int>> &cache) {
        if (cache[i][j] != -1) {
            return cache[i][j];
        }
        
        int k = i + j;
        if (k == s3.size()) {
            return true;
        }
        
        if (i < s1.size() and s1[i] == s3[k]) {
            cache[i][j] = areInterwoven(s1, s2, s3, i + 1, j, cache);
            if (cache[i][j]) {
                return true;
            }
        }
        
        if (j < s2.size() and s2[j] == s3[k]) {
            cache[i][j] = areInterwoven(s1, s2, s3, i, j + 1, cache);
            return cache[i][j];
        }
        
        cache[i][j] = false;
        return cache[i][j];
    }
};
