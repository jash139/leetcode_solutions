	class Solution {
public:
    string decodeString(string s) {
        vector<char> stack;
        
        for (auto ch : s) {
            if (ch != ']') {
                stack.push_back(ch);
            } else {
                string curStr = "";
                
                while (stack.back() != '[') {
                    curStr = stack.back() + curStr;
                    stack.pop_back();
                }
                
                stack.pop_back();
                
                string count = "";
                while (stack.size() > 0 and isdigit(stack.back())) {
                    count = stack.back() + count;
                    stack.pop_back();
                }
                
                int strCount = stoi(count);
                
                while (strCount--) {
                    cout<<curStr<<" ";
                    for (auto character : curStr)
                        stack.push_back(character);
                }
            }
        }
        
        string result = "";
        while (stack.size() > 0) {
            result = stack.back() + result;
            stack.pop_back();
        }
        
        return result;
    }
};
