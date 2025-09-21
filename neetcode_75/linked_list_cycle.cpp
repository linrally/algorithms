#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// tortoise and hare algorithm for cycle detection
bool hasCycle(ListNode *head) {
    if(not head) return false;
	ListNode* slow = head;
	ListNode* fast = head;
	while(slow->next and fast->next and fast->next->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) return true;
	}
	return false;
}

int main() {
	return 0;
}
