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
    ListNode* sortList(ListNode* head) {
        vector<int> values;
        ListNode* currentNode = head;
        while (currentNode != nullptr) {
            values.push_back(currentNode -> val);
            currentNode = currentNode -> next;
        }
        sort(values.begin(), values.end());
        currentNode = head;
        int i = 0;
        while (currentNode != nullptr) {
            currentNode -> val = values[i];
            i++;
            currentNode = currentNode -> next;
        }
        return head;
    }
};
