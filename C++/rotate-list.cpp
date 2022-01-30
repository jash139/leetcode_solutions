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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        
        ListNode* tail = head;
        ListNode* newHead = head;
        
        int size = 1;
        
        while (tail -> next != nullptr) {
            size++;
            tail = tail -> next;
        }
        tail -> next = head;
        
        k %= size;
        for (int i = 0; i < size - k; ++i) {
            tail = tail -> next;
        }
        
        newHead = tail -> next;
        tail -> next = nullptr;
        
        return newHead;
    }
};
