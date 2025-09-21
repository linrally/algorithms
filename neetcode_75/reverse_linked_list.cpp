#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// iterative
ListNode* reverseList(ListNode* head) {
	ListNode* cur = head;
	ListNode* prev = nullptr;
	while(cur){
		ListNode* temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}
	return prev;
}

// recursive
ListNode* reverseListRecursive(ListNode* cur) {
	if(not cur or not cur->next) return cur;
	ListNode* after = reverseListRecursive(cur->next);
    cur->next->next = cur; 
    cur->next = nullptr;
	return after;
}

int main() {
	return 0;
}
