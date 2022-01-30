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
        int height;
        int diameter;
    };
    
    int diameterOfBinaryTree(TreeNode* root) {
        return getDiameterOfBinaryTree(root).diameter;
    }
    
    TreeInfo getDiameterOfBinaryTree(TreeNode* node) {
        if (node == nullptr) {
            return TreeInfo {0, 0};
        }
        
        TreeInfo leftTreeInfo = getDiameterOfBinaryTree(node -> left);
        TreeInfo rightTreeInfo = getDiameterOfBinaryTree(node -> right);
        
        int diameterThroughRoot = leftTreeInfo.height + rightTreeInfo.height;
        int maxDiameterSoFar = max(leftTreeInfo.diameter, rightTreeInfo.diameter);
        
        int curHeight = max(leftTreeInfo.height, rightTreeInfo.height) + 1;
        int curDiameter = max(diameterThroughRoot, maxDiameterSoFar);
            
        
        return TreeInfo {curHeight, curDiameter};
    }
};
