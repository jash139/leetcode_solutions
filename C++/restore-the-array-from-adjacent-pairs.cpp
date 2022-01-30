class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> edges;
        
        for (auto pair : adjacentPairs) {
            edges[pair[0]].push_back(pair[1]);
            edges[pair[1]].push_back(pair[0]);
        }
        
        vector<int> originalArray;
        for (auto edge : edges)
            if (edge.second.size() == 1) {
                originalArray.push_back(edge.first);
                originalArray.push_back(edge.second[0]);
                break;
            }
        
        int len = adjacentPairs.size() + 1;
        
        while (originalArray.size() < len) {
            int tail = originalArray.back();
            int prev = originalArray[originalArray.size() - 2];
            auto next = edges[tail];
            if (next[0] != prev)
                originalArray.push_back(next[0]);
            else
                originalArray.push_back(next[1]);
        }
        
        return originalArray;
    }
};
