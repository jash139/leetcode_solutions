/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Put all nodes in stack and count size of list
    // Iterate half the size of list and at each
    // iteration join one node from head and one from tail
    
    void reorderList(ListNode* head) {
        if (head == nullptr or head -> next == nullptr or head -> next -> next == nullptr)
            return;
        
        stack<ListNode*> nodes;
        
        int listSize = 0;
        
        ListNode* currNode = head;
        while (currNode != nullptr) {
            nodes.push(currNode);
            currNode = currNode -> next;
            listSize++;
        }
        
        currNode = head;
        
        for (int i = 0; i < listSize / 2; ++i) {
            ListNode* lastNode = nodes.top();
            nodes.pop();
            
            lastNode -> next = currNode -> next;
            currNode -> next = lastNode;
            currNode = currNode -> next -> next;
        }
        
        currNode -> next = nullptr;
    }
};
