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
    struct TreeInfo {
        bool isBalanced;
        int height;
    };
    
    bool isBalanced(TreeNode* root) {
        return getTreeInfo(root).isBalanced;
    }
    
    TreeInfo getTreeInfo(TreeNode* node) {
        if (node == nullptr) {
            return TreeInfo {true, -1};
        }
        
        TreeInfo leftSubtreeInfo = getTreeInfo(node -> left);
        TreeInfo rightSubtreeInfo = getTreeInfo(node -> right);
        
        int heightDiff = abs(leftSubtreeInfo.height - rightSubtreeInfo.height);
        bool isBalanced = leftSubtreeInfo.isBalanced and rightSubtreeInfo.isBalanced and heightDiff <= 1;
        int height = max(leftSubtreeInfo.height, rightSubtreeInfo.height) + 1;
        
        return TreeInfo {isBalanced, height};
    }
};
