class Solution {
public:
    void dfs(int curIdx, vector<vector<int>> &isConnected, vector<bool> &visited) {
        visited[curIdx] = true;
        
        for (int i = 0; i < isConnected.size(); ++i) {
            if (curIdx != i and !visited[i] and isConnected[curIdx][i] == 1) {
                dfs(i, isConnected, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<bool> visited(n, false);
        
        int provinces = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                provinces++;
                dfs(i, isConnected, visited);
            }
        }
            
        return provinces;
    }
};
