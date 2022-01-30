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
    TreeNode* lca = nullptr;
    int getLCA(TreeNode* curNode, TreeNode* p, TreeNode* q) {
        if (curNode == nullptr or lca != nullptr) {
            return 0;
        }
        
        int left = getLCA(curNode -> left, p, q);
        int right = getLCA(curNode -> right, p, q);
        
        int mid = curNode == p or curNode == q ? 1 : 0;
        
        if (left + mid + right >= 2 and lca == nullptr) {
            lca = curNode;
        }
        return left + mid + right;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        getLCA(root, p, q);
        return lca;
    }
};
