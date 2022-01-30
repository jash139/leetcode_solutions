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
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        
        getSumOfEvenGrandparent(root, sum);
        
        return sum;
    }
    
    void getSumOfEvenGrandparent(TreeNode* node, int &sum) {
        if (node == nullptr)
            return;
        
        if (node -> val % 2 == 0) {
            sum += getChildrenSum(node);
        }
        
        getSumOfEvenGrandparent(node -> left, sum);
        getSumOfEvenGrandparent(node -> right, sum);
    }
    
    int getChildrenSum(TreeNode* node) {
        int sum = 0;
        if (node -> left != nullptr) {
            if (node -> left -> left != nullptr)
                sum += node -> left -> left -> val;
            if (node -> left -> right != nullptr)
                sum += node -> left -> right -> val;
        }
        
        if (node -> right != nullptr) {
            if (node -> right -> left != nullptr)
                sum += node -> right -> left -> val;
            if (node -> right -> right != nullptr)
                sum += node -> right -> right -> val;
        }
            
        return sum;
    }
};
