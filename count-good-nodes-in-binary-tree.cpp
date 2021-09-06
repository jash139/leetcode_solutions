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
    int goodNodes(TreeNode* root) {
        int goodNodesCount = 0;
        
        getGoodNodesCount(root, INT_MIN, goodNodesCount);
        
        return goodNodesCount;
    }
    
    void getGoodNodesCount(TreeNode* node, int maxSoFar, int &goodNodesCount) {
        if (node == nullptr)
            return;
        
        if (node -> val >= maxSoFar) {
            goodNodesCount++;
            maxSoFar = node -> val;
        }
        
        getGoodNodesCount(node -> left, maxSoFar, goodNodesCount);
        getGoodNodesCount(node -> right, maxSoFar, goodNodesCount);
    }
};
