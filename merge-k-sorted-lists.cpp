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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        else if (list2 == nullptr)
            return list1;
        
        if (list1 -> val < list2 -> val) {
            list1 -> next = mergeTwoLists(list1 -> next, list2);
            return list1;
        } else {
            list2 -> next = mergeTwoLists(list1, list2 -> next);
            return list2;
        }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        
        int len = lists.size();
        
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - i - 1]);
            }
            len = (len + 1) / 2;
        }
        
        return lists.front();
    }
};
