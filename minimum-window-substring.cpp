class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> targetCharCounts = getCharCounts(t);
        vector<int> substringBounds = getSubstringBounds(s, targetCharCounts);
        return getStringFromBounds(s, substringBounds);
    }
    
    unordered_map<char, int> getCharCounts(string str) {
        unordered_map<char, int> charCounts;
        for (char ch : str) {
            charCounts[ch]++;
        }
        return charCounts;
    }
    
    vector<int> getSubstringBounds(string str, unordered_map<char, int> targetCharCounts) {
        vector<int> substringBounds = {0, INT_MAX};
        unordered_map<char, int> substringCharCounts;
        int numUniqueChars = targetCharCounts.size();
        int numUniqueCharsDone = 0;
        
        int leftIdx = 0;
        int rightIdx = 0;
        
        while (rightIdx < str.size()) {
            char rightChar = str[rightIdx];
            
            if (targetCharCounts.find(rightChar) == targetCharCounts.end()) {
                rightIdx++;
                continue;
            }
            
            substringCharCounts[rightChar]++;
            if (substringCharCounts[rightChar] == targetCharCounts[rightChar]) {
                numUniqueCharsDone++;
            }
            
            while (numUniqueCharsDone == numUniqueChars and leftIdx <= rightIdx) {
                substringBounds = getCloserBounds(leftIdx, rightIdx, substringBounds[0], substringBounds[1]);
                
                char leftChar = str[leftIdx];
                if (targetCharCounts.find(leftChar) == targetCharCounts.end()) {
                    leftIdx++;
                    continue;
                }
                
                if (substringCharCounts[leftChar] == targetCharCounts[leftChar]) {
                    numUniqueCharsDone--;
                }
                substringCharCounts[leftChar]--;
                leftIdx++;
            }
            rightIdx++;
        }
        
        return substringBounds;
    }
    
    string getStringFromBounds(string str, vector<int> bounds) {
        int start = bounds[0];
        int end = bounds[1];
        
        if (end == INT_MAX)
            return "";
        
        return str.substr(start, end - start + 1);
    }
    
    vector<int> getCloserBounds(int idx1, int idx2, int idx3, int idx4) {
        return idx2 - idx1 < idx4 - idx3 ? vector<int>{idx1, idx2} : vector<int>{idx3, idx4};
    }
};
