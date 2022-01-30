class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int minCount = nums.size() / 3;
        unordered_map<int, int> elementCount;
        vector<int> result;
        
        for (int n : nums) {
            elementCount[n]++;
        }
        
        for (auto count : elementCount) {
            if (count.second > minCount) {
                result.push_back(count.first);
            }
        }
        
        return result;
    }
};
