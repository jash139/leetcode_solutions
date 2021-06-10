#include<bits/stdc++.h>
using namespace std;
 
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head = new ListNode(0);
    ListNode *n1 = l1, *n2 = l2, *cur = head;
    int carry = 0;
    while(n1 != nullptr or n2 != nullptr) {
        int a = n1 != nullptr ? n1 -> val : 0;
        int b = n2 != nullptr ? n2 -> val : 0;
        int sum = a + b + carry;
        carry = sum/10;
        sum %= 10;
        cur -> next = new ListNode(sum);
        cur = cur -> next;
        if (n1 != nullptr)
            n1 = n1 -> next;
        if (n2 != nullptr)
            n2 = n2 -> next;
    }
    if (carry > 0) 
        cur -> next = new ListNode(carry);
    return head -> next;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// pass two linked list 
	
	return 0;
}
