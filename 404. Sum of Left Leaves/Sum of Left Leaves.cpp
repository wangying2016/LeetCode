#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// my solution 1 , runtime = 6 ms
class Solution1 {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == nullptr) return 0;
		if (root->left == nullptr && root->right == nullptr) return 0;
		if (root->left) {
			if (root->left->left == nullptr && root->left->right == nullptr) count += root->left->val;
			else sumOfLeftLeaves(root->left);
		}
		if (root->right) sumOfLeftLeaves(root->right);
		return count;
	}
private:
	int count = 0;
};

// my solution 2 concise , runtime = 6 ms
class Solution2 {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root || (!root->left && !root->right)) return 0;
		if (root->left) !root->left->left && !root->left->right ? count += root->left->val : sumOfLeftLeaves(root->left);
		if (root->right) sumOfLeftLeaves(root->right);
		return count;
	}
private:
	int count = 0;
};

// my solution 3 concise , runtime = 3 ms
class Solution3 {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root && root->right) sumOfLeftLeaves(root->right);
		if (root && root->left) !root->left->left && !root->left->right ? count += root->left->val : sumOfLeftLeaves(root->left);
		return count;
	}
private:
	int count = 0;
};

// perfect solution , runtime = 6 ms
class Solution4 {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == nullptr) return 0;
		int count = 0;
		if (root->left != nullptr) {
			if (root->left->left == nullptr && root->left->right == nullptr) count += root->left->val;
			else count += sumOfLeftLeaves(root->left);
		}
		count += sumOfLeftLeaves(root->right);
		return count;
	}
};

int main()
{
	Solution4 solution;
	system("pause");
	return 0;
}