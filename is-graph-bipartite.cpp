class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // 0 -> not colored, 1 -> color1, -1 -> color2
        vector<int> nodeColor(graph.size(), 0);
        
        queue<int> q;
        
        for (int i = 0; i < graph.size(); ++i) {
            if (nodeColor[i])
                continue;
            
            nodeColor[i] = 1;
            q.push(i);
            
            while (!q.empty()) {
                int cur = q.front();
                
                for (auto neighbor : graph[cur]) {
                    if (!nodeColor[neighbor]) {
                        nodeColor[neighbor] = -nodeColor[cur];
                        q.push(neighbor);
                    } else if (nodeColor[neighbor] == nodeColor[cur])
                        return false;
                }
                q.pop();
            }
        }
        
        return true;
    }
};
