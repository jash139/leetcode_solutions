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
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        
        getRootToLeafSums(root, 0, totalSum);
        
        return totalSum;
    }
    
    void getRootToLeafSums(TreeNode* node, int runningNumber, int &totalSum) {
        if (node == nullptr)
            return;
        
        int currNumber = runningNumber * 10 + node -> val;
        if (node -> left == nullptr and node -> right == nullptr) {
            totalSum += currNumber;
            return;
        }
        
        getRootToLeafSums(node -> left, currNumber, totalSum);
        getRootToLeafSums(node -> right, currNumber, totalSum);
    }
};
