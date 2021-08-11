class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequencies(26, 0);
        for (auto task : tasks)
            frequencies[task - 'A']++;
        
        sort(frequencies.begin(), frequencies.end());
        
        int maxValue = frequencies[25] - 1;
        int idleSlots = maxValue * n;
        
        for (int i = 24; i >= 0; --i) {
            idleSlots -= min(maxValue, frequencies[i]);
        }
        
        return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
    }
};
