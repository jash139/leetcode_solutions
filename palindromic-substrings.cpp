class Solution {
public:
    int palinSubstringsCount = 0;
    
    void getPalindromeLengthFrom(string s, int left, int right) {
        while (left >= 0 and right < s.size() and s[left] == s[right]) {
            palinSubstringsCount++;
            left--;
            right++;
        }
    }
    
    int countSubstrings(string s) {
        for (int i = 0; i < s.size(); ++i) {
            getPalindromeLengthFrom(s, i, i);
            getPalindromeLengthFrom(s, i - 1, i);
        }
        
        return palinSubstringsCount;
    }
};
