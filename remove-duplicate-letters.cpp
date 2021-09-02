class Solution {
public:
    // O(n) Time | O(1) Space
    // n : length of string
    string removeDuplicateLetters(string s) {
        string result = "";
        
        vector<int> alphabetCount(26, 0);
        vector<int> isLetterUsed(26, 0);
        
        for (auto ch : s) {
            alphabetCount[ch - 'a']++;
        }
        
        for (auto ch : s) {
            alphabetCount[ch - 'a']--;
            
            if (isLetterUsed[ch - 'a'] > 0)
                continue;
            
            isLetterUsed[ch - 'a']++;
            
            while (result.size() > 0 and result.back() > ch and alphabetCount[result.back() - 'a'] > 0) {
                isLetterUsed[result.back() - 'a'] = 0;
                result.pop_back();
            }
            result.push_back(ch);
        }
            
        return result;
    }
};
