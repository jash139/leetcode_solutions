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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr or head -> next == nullptr or k == 1)
            return head;
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead -> next = head;
        
        ListNode* start = dummyHead;
        
        int i = 0;
        while (head != nullptr){
            i++;
            if (i % k == 0){
                start = reverseLinkedListInRange(start, head -> next);
                head = start -> next;
            } else {
                head = head -> next;
            }
        }
        return dummyHead -> next;
    }
    
    ListNode* reverseLinkedListInRange(ListNode* start, ListNode* end){
        ListNode* currentNode = start -> next;
        ListNode* next = nullptr;
        ListNode* first = currentNode;
        ListNode* previousNode = start;
        
        while (currentNode != end){
            next = currentNode -> next;
            currentNode -> next = previousNode;
            previousNode = currentNode;
            currentNode = next;
        }
        
        start -> next = previousNode;
        first -> next = currentNode;
        return first;
    }
};



---------------------------------------------------------------------



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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail = head;
        
        for (int i = 0; i < k; ++i) {
            if (tail == nullptr)
                return head;
            
            tail = tail -> next;
        }
        
        ListNode* newHead = reverseLinkedListTill(head, tail);
        head -> next = reverseKGroup(tail, k);
        
        return newHead;
    }
    
    ListNode* reverseLinkedListTill(ListNode* head, ListNode* tail) {
        ListNode* previousNode = nullptr;
        
        while (head != tail) {
            ListNode* nextNode = head -> next;
            head -> next = previousNode;
            previousNode = head;
            head = nextNode;
        }
        
        return previousNode;
    }
};
