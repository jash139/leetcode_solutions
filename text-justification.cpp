class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int start = 0;
        vector<string> result;
        
        while (start < words.size()) {
            int end = getEndWordIdx(start, words, maxWidth);
            result.push_back(justify(start, end, words, maxWidth));
            start = end + 1;
        }
        
        return result;
    }
    
    int getEndWordIdx(int start, vector<string> &words, int maxWidth) {
        int end = start;
        int currLength = words[end++].size();
        
        while (end < words.size() and (currLength + 1 + words[end].size() <= maxWidth)) {
            currLength += 1 + words[end].size();
            end++;
        }
        return end - 1;
    }
    
    string justify(int start, int end, vector<string> &words, int maxWidth) {
        if (end - start == 0)
            return addRightPadding(words[start], maxWidth);
        
        int spaceGroupsToAdd = end - start;
        int totalSpacesToAdd = maxWidth - findLengthInRange(start, end, words);
        bool isLastLine = end == words.size() - 1;
        
        string minSpaces = isLastLine ? " " : getSpacesOfLength(totalSpacesToAdd / spaceGroupsToAdd);
        int extraSpaces = isLastLine ? 0 : totalSpacesToAdd % spaceGroupsToAdd;
        
        string justifiedText = words[start];
        
        for (int idx = start + 1; idx <= end; ++idx) {
            justifiedText += minSpaces;
            justifiedText += extraSpaces-- > 0 ? " " : "";
            justifiedText += words[idx];
        }
        return addRightPadding(justifiedText, maxWidth);
    }
    
    int findLengthInRange(int start, int end, vector<string> &words) {
        int length = 0;
        for (int idx = start; idx <= end; ++idx) {
            length += words[idx].size();
        }
        return length;
    }
    
    string addRightPadding(string str, int maxWidth) {
        int paddingToAdd = maxWidth - str.size();
        return str + getSpacesOfLength(paddingToAdd);
    }
    
    string getSpacesOfLength(int len) {
        string spaces = "";
        for (int i = 0; i < len; ++i) {
            spaces.push_back(' ');
        }
        return spaces;
    }
};
