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
    int deepestLeavesSum(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int maxDepth = 1;
        int leafSums = 0;
        
        getDeepestLeavesSum(root, 1, maxDepth, leafSums);
        return leafSums;
    }
    
    void getDeepestLeavesSum(TreeNode* node, int currentDepth, int &maxDepth, int &leafSums) {
        if (node == nullptr)
            return;
        
        if (node -> left == nullptr and node -> right == nullptr) {
            if (currentDepth == maxDepth) {
                leafSums += node -> val;
            } else if (currentDepth > maxDepth) {
                leafSums = node -> val;
                maxDepth = currentDepth;
            }
        }
        
        getDeepestLeavesSum(node -> left, currentDepth + 1, maxDepth, leafSums);
        getDeepestLeavesSum(node -> right, currentDepth + 1, maxDepth, leafSums);
    }
};
