class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" or num2 == "0") {
            return "0";
        }
        
        vector<int> result(num1.size() + num2.size() - 1, 0);
        
        for (int i = 0; i < num1.size(); ++i) {
            for (int j = 0; j < num2.size(); ++j) {
                result[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        
        for (int i = result.size() - 1; i > 0; --i) {
            result[i - 1] += result[i] / 10;
            result[i] %= 10;
        }
        
        string product = "";
        for (auto n : result) {
            product += to_string(n);
        }
        
        return product;
    }
};
