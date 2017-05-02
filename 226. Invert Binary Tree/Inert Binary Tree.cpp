#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::swap;
using std::string;
using std::vector;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// my solution , runtime = 3 ms
class Solution1 {
public:
	void invertLeftRight(TreeNode *node) {
		if (node == nullptr) return;
		if (node->left != nullptr) invertLeftRight(node->left);
		if (node->right != nullptr) invertLeftRight(node->right);
		swap(node->left, node->right);
	}

	TreeNode* invertTree(TreeNode *root) {
		invertLeftRight(root);
		return root;
	}
};

// perfect solution , runtime = 3 ms
class Solution2 {
public:
	TreeNode* invertTree(TreeNode *root) {
		if (root) {
			invertTree(root->left);
			invertTree(root->right);
			swap(root->left, root->right);
		}
		return root;
	}
};

int main()
{
	Solution1 solution1;
	return 0;
}