class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> count(26, 0);
        
        for (int i = 0; i < s.size(); ++i) {
            count[(int)s[i] - 97]++;
            count[(int)t[i] - 97]--;
        }
        
        for (int c : count)
            if (c != 0)
                return false;
        
        return true;
    }
    
    
    // bool isAnagram(string s, string t) {
    //     sort(s.begin(), s.end());
    //     sort(t.begin(), t.end());
    //     return s == t;
    // }
};
