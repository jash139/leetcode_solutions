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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return checkPathSum(root, targetSum);
    }
    
    bool checkPathSum(TreeNode* node, int currSum) {
        if (node == nullptr)
            return false;
        
        if (node -> left == nullptr and node -> right == nullptr) {
            if (currSum == node -> val)
                return true;
            else
                return false;
        }
        
        bool resLeft = checkPathSum(node -> left, currSum - (node -> val));
        bool resRight = checkPathSum(node -> right, currSum - (node -> val));
        
        return resLeft or resRight;
    }
};
