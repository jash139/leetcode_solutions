class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> frequencies(nums.size() + 1, vector<int>{});
        
        unordered_map<int, int> frequencyMap;
        
        for (auto num : nums) {
            frequencyMap[num]++;
        }
        
        for (auto freq : frequencyMap) {
            frequencies[freq.second].push_back(freq.first);
        }
        
        vector<int> topFrequentElements;
        int count = 0;
        
        for (int f = frequencies.size() - 1; f >= 0; --f) {
            auto freq = frequencies[f];
            for (int i = 0; i < freq.size() and count < k; ++i) {
                topFrequentElements.push_back(freq[i]);
                count++;
            }
        }        
        return topFrequentElements;
    }
};
