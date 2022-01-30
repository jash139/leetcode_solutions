class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegreeCount(numCourses, 0);
        unordered_map<int, vector<int>> adjacencyList = initializeAdjacencyList(prerequisites, inDegreeCount);
        queue<int> zeroInDegreeNodes = getZeroInDegreeNodes(inDegreeCount);
        vector<int> ordering;
        
        int visitedCount = 0;
        while (!zeroInDegreeNodes.empty()) {
            int currNode = zeroInDegreeNodes.front();
            zeroInDegreeNodes.pop();
            ordering.push_back(currNode);
            visitedCount++;
            
            for (auto neighbor : adjacencyList[currNode]) {
                inDegreeCount[neighbor]--;
                
                if (inDegreeCount[neighbor] == 0) {
                    zeroInDegreeNodes.push(neighbor);
                }
            }
        }
        return visitedCount == numCourses ? ordering : vector<int> {};
    }
    
    unordered_map<int, vector<int>> initializeAdjacencyList( vector<vector<int>> prerequisites, vector<int> &inDegreeCount) {
        unordered_map<int, vector<int>> adjacencyList;
        
        for (vector<int> pair : prerequisites) {
            adjacencyList[pair[1]].push_back(pair[0]);
            inDegreeCount[pair[0]]++;
        }
        
        return adjacencyList;
    }
    
    queue<int> getZeroInDegreeNodes(vector<int> inDegreeCount) {
        queue<int> zeroInDegreeNodes;
        for (int i = 0; i < inDegreeCount.size(); ++i) {
            if (inDegreeCount[i] == 0) {
                zeroInDegreeNodes.push(i);
            }
        }
        return zeroInDegreeNodes;
    }
};
