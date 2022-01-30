class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> alphabetCount(26, 0);
        for (auto ch : t) {
            alphabetCount[ch - 'a']++;
        }
        for (auto ch : s) {
            alphabetCount[ch - 'a']--;
        }
        
        char diffChar;
        for (int i = 0; i < 26; ++i) {
            if (alphabetCount[i] > 0)
                diffChar = (char)(i + 97);
        }
        
        return diffChar;
    }
};
