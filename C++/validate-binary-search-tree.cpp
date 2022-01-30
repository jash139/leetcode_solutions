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
    bool validateBST(TreeNode* bst, long lowerLimit, long upperLimit) {
        if (bst == nullptr) return true;
        
        if (bst -> val <= lowerLimit or bst -> val >= upperLimit)
            return false;
    
        bool isLeftValid = validateBST(bst -> left, lowerLimit, bst -> val);
        bool isRightValid = validateBST(bst -> right, bst -> val, upperLimit);
        return isLeftValid and isRightValid;
    }
    bool isValidBST(TreeNode* root) {
        return validateBST(root, LONG_MIN, LONG_MAX);
    }
};
