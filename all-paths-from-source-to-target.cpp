class Solution {
public:
    void dfs(vector<vector<int>> graph, vector<vector<int>> &allPaths, vector<int> path, int currNode) {
        path.push_back(currNode);

        if (currNode == graph.size() - 1) {
            allPaths.push_back(path);
            return;
        }
        
        for (auto node : graph[currNode]) {
            dfs(graph, allPaths, path, node);
        }
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> allPaths;
        
        dfs(graph, allPaths, {}, 0);
        
        return allPaths;
    }
};
