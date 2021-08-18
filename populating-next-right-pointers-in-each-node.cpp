/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int len = q.size();
            
            for (int i = 0; i < len; ++i) {
                Node* curNode = q.front();
                q.pop();
                
                if (i != len - 1) {
                    curNode -> next = q.front();
                } else {
                    curNode -> next = nullptr;
                }
                
                if (curNode -> left) {
                    q.push(curNode -> left);
                }
                if (curNode -> right) {
                    q.push(curNode -> right);
                }
            }
        }
        
        return root;
    }
};
