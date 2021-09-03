class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n, 0);
        
        int i = 0;
        int j = n;
        
        while (i < n) {
            ans[i] = nums[i];
            ans[j] = nums[i];
            
            ++i;
            ++j;
        }
        
        return ans;
    }
};
