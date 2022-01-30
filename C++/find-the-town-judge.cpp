class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1 and trust.size() == 0) {
            return 1;
        }
        
        vector<int> outDegree(n + 1, 0);
        vector<int> inDegree(n + 1, 0);
        
        for (auto edge : trust) {
            outDegree[edge[0]]++;
            inDegree[edge[1]]++;
        }
        
        for (int i = 0; i < n + 1; ++i) {
            if (inDegree[i] == n - 1 and outDegree[i] == 0)
                return i;
        }
        
        return -1;
    }
};
