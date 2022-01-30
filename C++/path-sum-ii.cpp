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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> pathValues;
        
        getPathWithTarget(root, vector<int>{}, targetSum, pathValues);
        
        return pathValues;
    }
    
    void getPathWithTarget(TreeNode* node, vector<int> currentPath, int runningSum, vector<vector<int>> &pathValues) {
        if (node == nullptr)
            return;
        
        if (node -> left == nullptr and node -> right == nullptr and runningSum - node -> val == 0) {
            currentPath.push_back(node -> val);
            pathValues.push_back(currentPath);
            return;
        }
        
        currentPath.push_back(node -> val);
        getPathWithTarget(node -> left, currentPath, runningSum - node -> val, pathValues);
        getPathWithTarget(node -> right, currentPath, runningSum - node -> val, pathValues);
    }
};
