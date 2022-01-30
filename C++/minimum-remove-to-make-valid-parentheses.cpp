class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> stack;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                stack.push_back(i);
            else if (s[i] == ')') {
                if (stack.size() != 0)
                    stack.pop_back();
                else
                    s[i] = '*';
            }
        }
        
        while (stack.size() > 0) {
            int idx = stack.back();
            s[idx] = '*';
            stack.pop_back();
        }
        
        string res = "";
        
        for (int i = 0; i < s.size(); ++i)
            if (s[i] != '*')
                res += s[i];
        
        return res;
    }
};
