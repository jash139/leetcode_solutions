class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        unordered_map<char, int> isSeen;
        
        vector<int> longest = {0, 1};
        int startIdx = -1;
        
        for (int i = 0; i < s.size(); ++i) {
            char character = s[i];
            
            if (isSeen.find(character) != isSeen.end())
                startIdx = max(startIdx, isSeen[character]);
            
            if (longest[1] - longest[0] < i - startIdx)
                longest = {startIdx, i};
            
            isSeen[character] = i;
        }
        
        int result = longest[1] - longest[0];
        
        return result;
    }
};
