#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void maxDepthHelper(TreeNode *node, int&depth, int currDepth);

int maxDepth(TreeNode* root) {
    int depth = 0;
    int currDepth = 1;
    maxDepthHelper(root, depth, currDepth);
    return depth;
}

void maxDepthHelper(TreeNode *node, int &depth, int currDepth) {
    if (node == nullptr) return;
    if (currDepth > depth) {
        depth = currDepth;
    }
    maxDepthHelper(node -> left, depth, currDepth + 1);
    maxDepthHelper(node -> right, depth, currDepth + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// insert driver code
	
	return 0;
}
