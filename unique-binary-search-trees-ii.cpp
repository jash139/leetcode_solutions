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
    vector<TreeNode*> generateTrees(int n) {
        return generateTreesInRange(1, n);
    }
    
    vector<TreeNode*> generateTreesInRange(int start, int end) {
        if (start > end) {
            return vector<TreeNode*> {nullptr};
        }
        
        if (start == end) {
            return vector<TreeNode*> {new TreeNode(start)};
        }
        
        vector<TreeNode*> treeList;
        
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = generateTreesInRange(start, i - 1);
            vector<TreeNode*> right = generateTreesInRange(i + 1, end);
            
            for (auto leftNode : left) {
                for (auto rightNode : right) {
                    TreeNode* newRoot = new TreeNode(i);
                    newRoot -> left = leftNode;
                    newRoot -> right = rightNode;
                    
                    treeList.push_back(newRoot);
                }
            }
        }
        
        return treeList;
    }
};
