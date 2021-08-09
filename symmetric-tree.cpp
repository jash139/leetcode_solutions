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
    bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
        if (left == nullptr and right == nullptr)
            return true;
        if (left == nullptr or right == nullptr) 
            return false;
        bool isSymmetrical = isSymmetricHelper(left -> right, right -> left) and isSymmetricHelper(right -> left, left -> right);
        return left -> val == right -> val and isSymmetrical;
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelper(root, root);
    }
};
