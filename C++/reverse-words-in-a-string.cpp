class Solution {
public:
    string reverseWords(string s) {
        vector<string> reversedWords;
        
        string temp = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ' and temp != "") {
                reversedWords.insert(reversedWords.begin(), temp);
                temp = "";
            } else if (s[i] == ' ') {
                continue;
            } else {
                temp += s[i];
            }
        }
        
        if (temp != "")
            reversedWords.insert(reversedWords.begin(), temp);
        
        string res = "";
        
        for (int i = 0; i < reversedWords.size(); ++i) {
            if (i == 0)
                res += reversedWords[i];
            else 
                res += " " + reversedWords[i];
        }
            
        return res;
    }
};
