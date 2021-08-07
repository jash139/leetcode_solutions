class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        helper(result, "", n, n);
        return result;
    }
    void helper(vector<string> &res, string str, int left, int right){
        if(left == 0 and right == 0){
            res.push_back(str);
            return;
        }
        if(left > 0)
            helper(res, str + "(", left - 1, right);
        if(right > left)
            helper(res, str + ")", left, right - 1);
    }
};
