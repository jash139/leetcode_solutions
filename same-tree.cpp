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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p != nullptr and q != nullptr and p -> val == q -> val) {
        if (isSameTree(p -> left, q -> left) and isSameTree(p -> right, q -> right)) {
            return true;
        }
    } else if (p == nullptr and q == nullptr) {
        return true;
    }
    return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// insert driver code
	
	return 0;
}
