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
    void inorderTraverse(TreeNode* root, vector<int> &traversalValues) {
        if (root == nullptr) return;
        
        inorderTraverse(root -> left, traversalValues);
        traversalValues.push_back(root -> val);
        inorderTraverse(root -> right, traversalValues);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversalValues;
        inorderTraverse(root, traversalValues);
        return traversalValues;
    }
    
    // Iterative method using stack
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> traversalValues;
//         vector<TreeNode*> stack;
//         TreeNode* curr = root;
        
//         while (curr != nullptr or stack.size() != 0) {
//             while (curr != nullptr) {
//                 stack.push_back(curr);
//                 curr = curr -> left;
//             }
//             curr = stack[stack.size() - 1];
//             stack.pop_back();
//             traversalValues.push_back(curr -> val);
//             curr = curr -> right;
//         }
//         return traversalValues;
//     }
};
