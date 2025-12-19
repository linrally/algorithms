#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

static unordered_map<TreeNode*, int> mem;

int maxWeightIndependentSet(TreeNode* root){
	if(mem[root]) return mem[root];
	if(not root->left and not root->right) return mem[root] = root->val;
	int child = 0, grandchild = 0;
	if(root->left){
		child += maxWeightIndependentSet(root->left);
		if(root->left->left) grandchild += maxWeightIndependentSet(root->left->left);
		if(root->left->right) grandchild += maxWeightIndependentSet(root->left->right);
	}
	if(root->right){
		child += maxWeightIndependentSet(root->right);
		if(root->right->left) grandchild += maxWeightIndependentSet(root->right->left);
		if(root->right->right) grandchild += maxWeightIndependentSet(root->right->right);
	}
	return mem[root] = max(child, grandchild + root->val);
}

int main() {
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(20);
	root->right = new TreeNode(30);
	root->right->right = new TreeNode(60);
	root->left->left = new TreeNode(40);
	root->left->right = new TreeNode(50);
	root->left->right->left = new TreeNode(70);
	root->left->right->right = new TreeNode(80);
	cout << maxWeightIndependentSet(root) << endl;
	return 0;
}
