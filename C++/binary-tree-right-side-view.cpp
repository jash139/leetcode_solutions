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
    void getRightSideValues(TreeNode* node, vector<int> &rightViewValues, int currDepth, int &maxDepth) {
        if (node == nullptr)
            return;
        
        if (currDepth > maxDepth) {
            rightViewValues.push_back(node -> val);
            maxDepth = currDepth;
        }
        
        getRightSideValues(node -> right, rightViewValues, currDepth + 1, maxDepth);
        getRightSideValues(node -> left, rightViewValues, currDepth + 1, maxDepth);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        int maxDepth = 0;
        vector<int> rightViewValues;
        getRightSideValues(root, rightViewValues, 1, maxDepth);
        return rightViewValues;
    }
};
