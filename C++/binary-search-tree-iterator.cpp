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
class BSTIterator {
    stack<TreeNode*> nodesStack;
public:
    BSTIterator(TreeNode *root) {
        pushLeftNodesToStack(root);
    }

    int next() {
        TreeNode* currNode = nodesStack.top();
        nodesStack.pop();
        
        if (currNode -> right != nullptr)
            pushLeftNodesToStack(currNode -> right);
            
        return currNode -> val;
    }
    
    bool hasNext() {
        if (nodesStack.empty())
            return false;
        
        return true;
    }
    
    void pushLeftNodesToStack(TreeNode* root) {
        TreeNode* currNode = root;
        
        while (currNode != nullptr) {
            nodesStack.push(currNode);
            currNode = currNode -> left;
        }
    }
    

----------------------------------------------------------------------

    
	vector<TreeNode*> inorder;
	int pos;
public:
	BSTIterator(TreeNode* root) {
		inorderTraverseNodes(root);
		pos = -1;
	}
	
	void inorderTraverseNodes(TreeNode* currNode) {
		if (currNode == nullptr)
			return;
		inorderTraverseNodes(currNode -> left);
		inorder.push_back(currNode);
		inorderTraverseNodes(currNode -> right);
	}
	
	int next() {
		pos++;
		return inorder[pos] -> val;
	}
	
	bool hasNext() {
		if (pos + 1 < inorder.size())
			return true;
		
		return false;
	}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
