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

TreeNode* invertTree(TreeNode* root) {
	if(root == nullptr){
		return root;		
	}
	TreeNode* left = invertTree(root->left);
	TreeNode* right  = invertTree(root->right);

	// NB: this is wrong because we are reassigning root->left
	// root->left = invertTree(root->right);
	// root->right = invertTree(root->left);

	root->left = right;
	root->right = left;
	return root;
}

int main() {
	return 0;
}
