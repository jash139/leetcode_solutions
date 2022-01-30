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
    TreeNode* constructBinaryTree(vector<int> inorder, vector<int> postorder, int leftIdx, int rightIdx, int &rootIdx, unordered_map<int, int> &inorderPositions) {
        if (leftIdx > rightIdx)
            return nullptr;
        
        int pivotIdx = inorderPositions[postorder[rootIdx]];
        rootIdx--;
        
        TreeNode* root = new TreeNode(inorder[pivotIdx]);
        
        root -> right = constructBinaryTree(inorder, postorder, pivotIdx + 1, rightIdx, rootIdx, inorderPositions);
        root -> left = constructBinaryTree(inorder, postorder, leftIdx, pivotIdx - 1, rootIdx, inorderPositions);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderPositions;
        int rootIdx = postorder.size() - 1;
        
        for (int idx = 0; idx < inorder.size(); ++idx) {
            inorderPositions[inorder[idx]] = idx;
        }
        
        return constructBinaryTree(inorder, postorder, 0, inorder.size() - 1, rootIdx, inorderPositions);
    }
};
