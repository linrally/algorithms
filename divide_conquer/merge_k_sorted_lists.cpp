#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
	if(lists.size() == 0) return nullptr;
	if(lists.size() == 1) return lists[0];
	vector<ListNode*> l, r;
	for(int i = 0; i < lists.size(); i++){
		if(i % 2 == 0) l.push_back(lists[i]);
		else r.push_back(lists[i]);
	}
	ListNode* lm = mergeKLists(l);
	ListNode* rm = mergeKLists(r);

	// merge 2 lists
	ListNode* res = new ListNode();
	ListNode* head = res;
	while(lm != nullptr or rm != nullptr){
		if(lm != nullptr and rm != nullptr){
			if(lm->val < rm->val){
				res->next = lm;
				lm = lm->next;
			} else {
				res->next = rm;
				rm = rm->next;
			}
		}
		else if(lm != nullptr){
			res->next = lm;
			lm = lm->next;
		}
		else if(rm != nullptr){
			res->next = rm;
			rm = rm->next;
		}
		res = res->next;
	}

	return head->next;
}

static void printLL(ListNode* list){
	while(list != nullptr){
		cout << list->val << " ";
		list = list->next;
	}
	cout << endl;
}

int main() {
	vector<ListNode*> lists(3);
	lists[0] = new ListNode(1, new ListNode(4, new ListNode(5)));
	lists[1] = new ListNode(1, new ListNode(3, new ListNode(4)));
	lists[2] = new ListNode(2, new ListNode(6));
	
	ListNode* res = mergeKLists(lists);

	printLL(res);

	return 0;
}
