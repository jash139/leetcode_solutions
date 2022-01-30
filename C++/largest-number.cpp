class Solution {
public:

    string largestNumber(vector<int>& nums) {
        vector<string> numbers;
        for (int i = 0; i < nums.size(); ++i)
            numbers.push_back(to_string(nums[i]));
        
        sort(numbers.begin(), numbers.end(), [](string a, string b) {return a + b > b + a;});
        
        if (numbers[0] == "0") return "0";
        
        string res = "";
        for (int i = 0; i < numbers.size(); ++i)
            res += numbers[i];
        return res;
    }
};
