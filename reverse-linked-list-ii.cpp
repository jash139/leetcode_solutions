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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        
        ListNode *prevNode = dummy;
        ListNode *currNode;
        
        for (int i = 0; i < left - 1; i++) {
            prevNode = prevNode -> next;
        }
        
        currNode = prevNode -> next;
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = prevNode -> next;
            
            prevNode -> next = currNode -> next;
            currNode -> next = currNode -> next -> next;
            prevNode -> next -> next = temp;
        }
        
        return dummy -> next;
    }
};
