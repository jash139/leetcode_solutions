class Solution {
public:
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    
    void getAllPartitions(vector<vector<string>> &result, int startIdx, string s, vector<string> curPartition) {
        if (startIdx == s.size()) {
            result.push_back(curPartition);
            return;
        }
        
        for (int i = startIdx; i < s.size(); ++i) {
            if (isPalindrome(s, startIdx, i)) {
                curPartition.push_back(s.substr(startIdx, i - startIdx + 1));
                getAllPartitions(result, i + 1, s, curPartition);
                curPartition.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        
        vector<string> curPartition;
        getAllPartitions(result, 0, s, curPartition);
        
        return result;
    }
};
