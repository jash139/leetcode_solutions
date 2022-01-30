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
    TreeNode* firstNode;
    TreeNode* secondNode;
    TreeNode* previousNode;
    
    void recoverTree(TreeNode* root) {
        firstNode = nullptr;
        secondNode = nullptr;
        previousNode = nullptr;
        
        getNodesToSwap(root);
        
        int temp = firstNode -> val;
        firstNode -> val = secondNode -> val;
        secondNode -> val = temp;
    }
    
    void getNodesToSwap(TreeNode* currNode) {
        if (currNode == nullptr)
            return;
        
        getNodesToSwap(currNode -> left);
        
        if (firstNode == nullptr and previousNode != nullptr and currNode -> val <= previousNode -> val) {
            firstNode = previousNode;
        }
        
        if (firstNode != nullptr and previousNode != nullptr and currNode -> val <= previousNode -> val) {
            secondNode = currNode;
        }
        
        previousNode = currNode;
        
        getNodesToSwap(currNode -> right);
    }
};
