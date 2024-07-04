#include <iostream>
using namespace std;

class treenode {
public:
	int val;
	treenode* left;
	treenode* right;
	treenode(int x) :val(x), left(nullptr), right(nullptr) {}
};

void inorder(treenode* root) {
	if (root) {
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
}
int main() {
	treenode* root = new treenode(1);
	root->left = new treenode(2);
	root->right = new treenode(3);
	root->left->left = new treenode(4);
	root->left->right = new treenode(5);
	cout << "Inorder traversal: ";
	inorder(root);
	cout << endl;
}