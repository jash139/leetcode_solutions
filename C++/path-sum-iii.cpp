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
    void getPathSum(TreeNode* root, int currSum, int target, unordered_map<int, int> &prefixSums, int &numOfPaths) {
        if (root == nullptr)
            return;
        
        currSum += root -> val;
        
        if (prefixSums.find(currSum - target) != prefixSums.end()) {
            numOfPaths += prefixSums[currSum - target];
        }
        
        prefixSums[currSum]++;
        
        getPathSum(root -> left, currSum, target, prefixSums, numOfPaths);
        getPathSum(root -> right, currSum, target, prefixSums, numOfPaths);
        
        prefixSums[currSum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> prefixSums;
        prefixSums[0] = 1;
        
        int numOfPaths = 0;
        getPathSum(root, 0, targetSum, prefixSums, numOfPaths);
        
        return numOfPaths;
    }
 
//     int getPathSumFrom(TreeNode* node, int sum) {
//         if (node == nullptr) {
//             return 0;
//         }
        
//         return (node -> val == sum ? 1 : 0) + getPathSumFrom(node -> left, sum - node -> val) + getPathSumFrom(node -> right, sum - node -> val);
//     }
    
//     int pathSum(TreeNode* root, int targetSum) {
//         if (root == nullptr)
//             return 0;
        
//         return getPathSumFrom(root, targetSum) + pathSum(root -> left, targetSum) + pathSum(root -> right, targetSum);
//     }
};
