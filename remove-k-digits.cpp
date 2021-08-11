class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        
        for (auto n : num) {
            while (ans.size() and ans.back() > n and k) {
                ans.pop_back();
                k--;
            }
            if (ans.size() or n != '0')
                ans.push_back(n);
        }
        
        while (ans.size() and k) {
            ans.pop_back();
            k--;
        }
        
        return ans == "" ? "0" : ans;
    }
};
