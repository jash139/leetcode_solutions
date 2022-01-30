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
    vector<int> tryRob(TreeNode* root) {
        if (root == nullptr)
            return vector<int>{0, 0};
        
        vector<int> leftVal = tryRob(root -> left);
        vector<int> rightVal = tryRob(root -> right);
        
        int withRoot = root -> val + leftVal[1] + rightVal[1];
        int withoutRoot = max(leftVal[0], leftVal[1]) + max(rightVal[0], rightVal[1]);
        
        return vector<int> {withRoot, withoutRoot};
    }
    
    int rob(TreeNode* root) {
        vector<int> values = tryRob(root);
        return max(values[0], values[1]);
    }
};
