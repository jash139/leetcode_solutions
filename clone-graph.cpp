/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* clone(Node* node, unordered_map<Node*, Node*> &copies) {
        if (node == nullptr)
            return node;
        
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node -> val, {});
            for (auto neighbor : node -> neighbors) {
                copies[node] -> neighbors.push_back(clone(neighbor, copies));
            }
        }
        return copies[node];
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> copies;
        return clone(node, copies);
    }
};
