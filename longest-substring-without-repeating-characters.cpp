class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int idx = 0;
        int maxSubstringLength = 0;
        
        while (idx < s.length()) {
            int curIdx = idx;
            int curLength = 0;
            unordered_map<char, int> isCharPresent;
            while (curIdx < s.length()) {
                if (isCharPresent.find(s[curIdx]) != isCharPresent.end()) {
                    curIdx = isCharPresent[s[curIdx]];
                    break;
                }
                isCharPresent[s[curIdx]] = curIdx;
                curLength++;
                curIdx++;
            }
            maxSubstringLength = max(curLength, maxSubstringLength);
            idx = curIdx + 1;
        }
        
        return maxSubstringLength;
    }
};
