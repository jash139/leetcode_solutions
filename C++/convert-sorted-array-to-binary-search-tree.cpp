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
    TreeNode* constructBST(vector<int> nums, int leftIdx, int rightIdx) {
        if (leftIdx > rightIdx) {
            return nullptr;
        }
        
        int middleIdx = (leftIdx + rightIdx) / 2;
        
        TreeNode* root = new TreeNode(nums[middleIdx]);
        
        root -> left = constructBST(nums, leftIdx, middleIdx - 1);
        root -> right = constructBST(nums, middleIdx + 1, rightIdx);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(nums, 0, nums.size() - 1);
    }
};
