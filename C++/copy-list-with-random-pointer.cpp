/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return head;
        
        Node* currNode = head;
        
        // Create duplicate of each node
        // and link them just after original node
        while (currNode != nullptr) {
            Node* nextNode = currNode -> next;
            currNode -> next = new Node(currNode -> val);
            currNode -> next -> next = nextNode;
            
            currNode = nextNode;
        }
        
        currNode = head;
        
        // Assign random pointers for 
        // duplicate nodes
        while (currNode != nullptr) {
            if (currNode -> random != nullptr) 
                currNode -> next -> random = currNode -> random -> next;

            currNode = currNode -> next -> next;
        }
        
        currNode = head;
        Node* copyHead = head -> next;
        
        // Restore original list & 
        // Extract duplicate list
        while (currNode != nullptr) {
            Node* nextNode = currNode -> next -> next;
            Node* copyNode = currNode -> next;
            currNode -> next = nextNode;
            
            if (nextNode != nullptr) {
                copyNode -> next = nextNode -> next;
            }
            
            currNode = nextNode;
        }
        
        return copyHead;
    }
};
