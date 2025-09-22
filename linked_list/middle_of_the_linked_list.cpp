#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
		if(head->next == nullptr) return head;
		ListNode *slow = head->next;
		ListNode *fast = head->next->next;
		while(fast != nullptr and fast->next != nullptr){
				slow = slow->next;
				fast = fast->next->next;
		}
		return slow;
}

int main() {
	return 0;
}
