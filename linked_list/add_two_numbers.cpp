#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// digits are stored in reverse order
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int carry = 0;
	ListNode res;
	ListNode* cur = &res;
	while(carry != 0 or l1 or l2){
		int sum = carry;
		if(l1){
			sum += l1->val;
			l1 = l1->next;
		}
		if(l2){
			sum += l2->val;
			l2 = l2->next;
		}
		if(sum >= 10){
			sum = sum % 10;
			carry = 1;
		} else {
            carry = 0;
        }
		cur->next = new ListNode(sum);
		cur = cur->next;
	}
	return res.next;
}

int main() {
	return 0;
}
