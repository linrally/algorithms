#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverse(ListNode* cur){
	if(not cur or not cur->next) return cur;
	ListNode* after = reverse(cur->next);
	cur->next->next = cur;
	cur->next = nullptr;
	return after;
}

ListNode* middle(ListNode* head) {
		if(head->next == nullptr) return head;
		ListNode *slow = head->next;
		ListNode *fast = head->next->next;
		while(fast != nullptr and fast->next != nullptr){
				slow = slow->next;
				fast = fast->next->next;
		}
		return slow;
}

void reorderList(ListNode* head){
	ListNode* mid = middle(head);
	ListNode* rev = reverse(mid);
	ListNode* cur = head;
	while(cur->next and rev->next){
		ListNode* temp = cur->next;
		cur->next = rev;
		cur = temp;

		temp = rev->next;
		rev->next = cur;
		rev = temp;
	}
}

int main() {
	return 0;
}
