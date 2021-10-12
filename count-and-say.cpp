class Solution {
public:
    string getCountAndSayValue(string s) {
        int currCount = 1;
        char prevChar = s[0];
        string result = "";
        
        for (int i = 1; i < s.size(); ++i) {
            char currChar = s[i];
            if (currChar == prevChar) {
                currCount++;
                continue;
            }
            
            result += to_string(currCount);
            result += prevChar;
            
            prevChar = currChar;
            currCount = 1;
        }
        
        result += to_string(currCount);
        result += prevChar;
        
        return result;
    }
    
    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; ++i) {
            result = getCountAndSayValue(result);
        }
        return result;
    }
};
