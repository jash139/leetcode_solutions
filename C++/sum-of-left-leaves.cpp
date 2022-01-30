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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr or root -> left == nullptr and root -> right == nullptr)
            return 0;
        
        int totalSum = 0;
        getSumOfLeftLeaves(root, true, totalSum);
        
        return totalSum;
    }
    
    void getSumOfLeftLeaves(TreeNode* node, bool isLeft, int &totalSum) {
        if (node == nullptr)
            return;
        
        if (isLeft and node -> left == nullptr and node -> right == nullptr) {
            totalSum += node -> val;
            return;
        }
        
        getSumOfLeftLeaves(node -> left, true, totalSum);
        getSumOfLeftLeaves(node -> right, false, totalSum);
    }
};
