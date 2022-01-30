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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stack;
        
        for (int i = 0; i < nums.size(); ++i) {
            TreeNode* currNode = new TreeNode(nums[i]);
            
            while (!stack.empty() and stack.back() -> val < nums[i]) {
                currNode -> left = stack.back();
                stack.pop_back();
            }
            
            if (!stack.empty())
                stack.back() -> right = currNode;
            
            stack.push_back(currNode);
        }
        return stack.front();
    }
};
