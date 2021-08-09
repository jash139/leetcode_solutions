/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> isPresent;
        
        while (headA != nullptr) {
            isPresent.insert(headA);
            headA = headA -> next;
        }
        
        while (headB != nullptr) {
            if (isPresent.find(headB) != isPresent.end())
                return headB;
            headB = headB -> next;
        }
        
        return nullptr;
    }
};
