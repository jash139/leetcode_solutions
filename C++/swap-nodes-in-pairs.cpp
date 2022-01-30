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
    ListNode* swapPairs(ListNode* head) {
       if (head == nullptr or head -> next == nullptr)
           return head;
        
        ListNode* newHead = new ListNode(0);
        newHead -> next = head;
        
        ListNode* prevNode = newHead; 
        ListNode* currNode = head;
        
        while (prevNode -> next != nullptr and currNode -> next != nullptr) {
            prevNode -> next = currNode -> next;
            currNode -> next = currNode -> next -> next;
            prevNode -> next -> next = currNode;
            
            prevNode = currNode;
            currNode = prevNode -> next;
        }
        return newHead -> next;
    }
    
//     ListNode* swapPairs(ListNode* head) {
//         if (head == nullptr or head -> next == nullptr)
//             return head;
        
//         ListNode* nextNodeGroup = head -> next -> next;
//         ListNode* prevNode = head;
//         ListNode* nextNode = head -> next;
        
//         head = nextNode;
//         head -> next = prevNode;
//         head -> next -> next = swapPairs(nextNodeGroup);
        
//         return head;
//     }
};
