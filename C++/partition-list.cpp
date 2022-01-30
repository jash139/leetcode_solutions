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
    // n : number of nodes in the linked list
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallerHead = new ListNode(0);
        ListNode* smallerNodes = smallerHead;
        
        ListNode* greaterHead = new ListNode(0);
        ListNode* greaterNodes = greaterHead;
        
        while (head != nullptr) {
            if (head -> val < x) {
                smallerNodes -> next = head;
                smallerNodes = smallerNodes -> next;
            } else {
                greaterNodes -> next = head;
                greaterNodes = greaterNodes -> next;
            }
            
            head = head -> next;
        }
        
        greaterNodes -> next = nullptr;
        smallerNodes -> next = greaterHead -> next;
            
        return smallerHead -> next;
    }
};
