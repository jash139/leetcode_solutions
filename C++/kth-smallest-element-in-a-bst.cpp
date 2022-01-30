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
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> stack;
        
        while (true) {
            while (root != nullptr) {
                stack.push_back(root);
                root = root -> left;
            }
            root = stack[stack.size() - 1];
            stack.pop_back();
            k--;
            if (k == 0) return root -> val;
            root = root -> right;
        }
    }
};
