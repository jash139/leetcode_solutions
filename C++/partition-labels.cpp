class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOccurrence(26, 0);
        for (int i = 0; i < s.size(); ++i)
            lastOccurrence[s[i] - 'a'] = i;
        
        vector<int> partitionSizes;
        
        int startOfPartition = 0;
        int endOfPartition = 0;
        for (int i = 0; i < s.size(); ++i) {
            char curChar = s[i];
            endOfPartition = max(endOfPartition, lastOccurrence[curChar - 'a']);
            
            if (i == endOfPartition) {
                partitionSizes.push_back(endOfPartition - startOfPartition + 1);
                startOfPartition = i + 1;
            }
        }
        
        return partitionSizes;
    }
};
