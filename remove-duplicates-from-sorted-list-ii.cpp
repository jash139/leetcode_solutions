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
    // O(n) Time | O(1) Space
    // n : number of nodes
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        newHead -> next = head;
        
        ListNode* prev = newHead;
        while (head != nullptr) {
            if (head -> next != nullptr and head -> val == head -> next -> val) {
                while (head -> next != nullptr and head -> val == head -> next -> val) {
                    head = head -> next;
                }
                prev -> next = head -> next;
            } else {
                prev = prev -> next;
            }
            head = head -> next;
        }
        
        return newHead -> next;
    }
};
