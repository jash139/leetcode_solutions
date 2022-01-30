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
    int maxSum;
    
    int getMaximumValue(int num1, int num2, int num3, int num4) {
        int maxValue = max(num1, max(num2, max(num3, num4)));
        return maxValue;
    }
    
    int getMaxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftMax = getMaxPathSum(root -> left);
        int rightMax = getMaxPathSum(root -> right);
        
        int rootSum = root -> val;
        int leftPathSum = root -> val + leftMax;
        int rightPathSum = root -> val + rightMax;
        int rootPathSum = root -> val + leftMax + rightMax;
        
        int maxOfAllPaths = getMaximumValue(rootSum, leftPathSum, rightPathSum, rootPathSum);
        
        maxSum = max(maxSum, maxOfAllPaths);
        
        return max(rootSum, max(leftPathSum, rightPathSum));
    }
    
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        getMaxPathSum(root);
        return maxSum;
    }
};
