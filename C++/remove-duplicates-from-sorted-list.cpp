#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
};
 
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* curr = head;
    while(curr != nullptr) {
        if (curr -> next != nullptr and curr -> next -> val == curr -> val) {
            curr -> next = curr -> next -> next;
            continue;
        }
        curr = curr -> next;
    }
    return head;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// pass linked list 
	
	return 0;
}
