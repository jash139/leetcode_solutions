class Solution {
public:
    void getAllCombinations(vector<string> &allCombinations, unordered_map<char, string> numberMap, string combination, string digits, int startIdx) {
        if (combination.size() == digits.size()) {
            allCombinations.push_back(combination);
            return;
        }
        
        for (auto character : numberMap[digits[startIdx]]) {
            getAllCombinations(allCombinations, numberMap, combination + character, digits, startIdx + 1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return vector<string> {};
        unordered_map<char, string> numberMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        vector<string> allCombinations;
        string combination = "";
        
        getAllCombinations(allCombinations, numberMap, combination, digits, 0);
        
        return allCombinations;
    }
};
