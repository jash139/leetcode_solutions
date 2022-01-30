/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* clonedTargetReference;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        clonedTargetReference = nullptr;
        getTargetNode(original, cloned, target);
        return clonedTargetReference;
    }
    
    void getTargetNode(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr) {
            return;
        }
        
        if (original == target) {
            clonedTargetReference = cloned;
            return;
        }
        
        getTargetNode(original -> left, cloned -> left, target);
        getTargetNode(original -> right, cloned -> right, target);
    }
};
