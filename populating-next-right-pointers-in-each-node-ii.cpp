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
        queue<Node*> levelNodes;
        levelNodes.push(root);
        
        while (!levelNodes.empty()) {
            int currSize = levelNodes.size();
            Node* prevNode = nullptr;
            
            for (int i = 0; i < currSize; ++i) {
                Node* currNode = levelNodes.front();
                levelNodes.pop();
                
                if (currNode == nullptr)
                    continue;
                
                currNode -> next = prevNode;
                prevNode = currNode;
                
                levelNodes.push(currNode -> right);
                levelNodes.push(currNode -> left);
            }
        }
        
        return root;
    }
};
