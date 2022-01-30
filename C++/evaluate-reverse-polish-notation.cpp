class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> operations({"+", "-", "*", "/"});
        vector<int> stack;
        
        for (auto token : tokens) {
            if (operations.find(token) == operations.end())
                stack.push_back(stoi(token));
            else {
                int b = stack.back();
                stack.pop_back();
                int a = stack.back();
                stack.pop_back();
                if (token == "+")
                    stack.push_back(a + b);
                else if (token == "-")
                    stack.push_back(a - b);
                else if (token == "*")
                    stack.push_back(a * b);
                else
                    stack.push_back(a / b);
            }
        }
        return stack.back();
    }
};
