#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}

bool isSameTree(TreeNode* p, TreeNode* q) {
	if(p == nullptr and q == nullptr) return true;
	if(p == nullptr or q == nullptr) return false;
	bool left = isSameTree(p->left, q->left);
	bool right = isSameTree(p->right, q->right);
	return left and right and p->val == q->val;
}

int main() {
	return 0;
}
