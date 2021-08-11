class Solution {
public:
    int minDeletions(string s) {
        vector<int> frequencies(26, 0);
        for (auto ch : s)
            frequencies[ch - 'a']++;
        
        
        sort(frequencies.begin(), frequencies.end(), greater<int>());
        
        int keepCount = 0;
        int prev = INT_MAX;
        for (auto frequency : frequencies) {
            if (frequency == 0 or prev == 0)
                break;
            
            prev = min(frequency, prev - 1);
            keepCount += prev;
        }
        
        int deletions = s.size() - keepCount;
        return deletions;
    }
};
