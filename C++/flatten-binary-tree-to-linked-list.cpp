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
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        
        // Temporarily store right subtree
        // Make left subtree the right subtree
        // Make left as null
        // Move to the end of the new right subtree (previously left subtree)
        // and append the stored right subtree
        // recursively call flatten on right 
        
        TreeNode* rightSubtree = root -> right;
        root -> right = root -> left;
        root -> left = nullptr;
        
        TreeNode* currentNode = root;
        
        while (currentNode -> right) {
            currentNode = currentNode -> right;
        }
        
        currentNode -> right = rightSubtree;
        
        flatten(root -> right);
    }
};
