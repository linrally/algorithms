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

// Naive DFS approach

string serialize(TreeNode* root){
	 if(root == nullptr) return "#";
	 return "&" + root->val + serialize(root->left) + serialize(root->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
	string rs = serialize(root);
	string ss = serialize(subRoot);
	return rs.find(ss) != string::npos;
}

int main() {
	return 0;
}
