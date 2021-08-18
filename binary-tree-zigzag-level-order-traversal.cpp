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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> traversalValues;
        vector<int> levelValues;
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        bool dirRight = true;
        
        while (!q.empty()) {
            if (q.front() -> left) {
                q.push(q.front() -> left);
            }
            if (q.front() -> right) {
                q.push(q.front() -> right);
            }
            levelValues.push_back(q.front() -> val);
            q.pop();
            count--;
            if (count == 0) {
                if (!dirRight) {
                    reverse(levelValues.begin(), levelValues.end());
                }
                traversalValues.push_back(levelValues);
                dirRight = !dirRight;
                levelValues = {};
                count = q.size();
            }
        }
        
        return traversalValues;
    }
};
