/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> bottomUpTraversal;
        queue<TreeNode*> levelNodes;
        
        levelNodes.push(root);
        
        while (!levelNodes.empty()) {
            int currSize = levelNodes.size();
            
            vector<int> currLevel = {};
            for (int i = 0; i < currSize; ++i) {
                TreeNode* currNode = levelNodes.front();
                levelNodes.pop();
                
                if (currNode == nullptr)
                    continue;
                
                currLevel.push_back(currNode -> val);
                
                levelNodes.push(currNode -> left);
                levelNodes.push(currNode -> right);
            }
            if (currLevel.size() > 0)
                bottomUpTraversal.push_back(currLevel);
        }
        
        reverse(bottomUpTraversal.begin(), bottomUpTraversal.end());
        
        return bottomUpTraversal;
    }
};
