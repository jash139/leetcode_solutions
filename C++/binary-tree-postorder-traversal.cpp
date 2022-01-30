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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorderTraversalValues;
        getPostorderTraversalValues(root, postorderTraversalValues);
        return postorderTraversalValues;
    }
    
    void getPostorderTraversalValues(TreeNode* node, vector<int> &values) {
        if (node == nullptr)
            return;
        
        getPostorderTraversalValues(node -> left, values);
        getPostorderTraversalValues(node -> right, values);
        values.push_back(node -> val);
    }
};
