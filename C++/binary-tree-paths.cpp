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
    void getBinaryTreePaths(TreeNode* currNode, vector<string> &result, string currString) {
        if (!currNode -> left && !currNode -> right) {
            result.push_back(currString);
            return;
        } 
        
        if (currNode -> left) {
            getBinaryTreePaths(currNode -> left, result, currString + "->" + to_string(currNode -> left -> val));
        }
        if (currNode -> right) {
            getBinaryTreePaths(currNode -> right, result, currString + "->" + to_string(currNode -> right -> val));
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root)
            return {};
        
        vector<string> result;
        getBinaryTreePaths(root, result, to_string(root -> val));
        return result;
    }
};
