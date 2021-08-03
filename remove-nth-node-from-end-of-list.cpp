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
    // O(L) Time | O(1) Space
    // L : number of nodes in list
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* currentNode = dummy;
        ListNode* nextNode = dummy;
        
        for (int i = 0; i <= n; ++i)
            nextNode = nextNode -> next;
        
        while (nextNode != nullptr) {
            currentNode = currentNode -> next;
            nextNode = nextNode -> next;
        }
        currentNode -> next = currentNode -> next -> next;
        return dummy -> next;
    }
};
