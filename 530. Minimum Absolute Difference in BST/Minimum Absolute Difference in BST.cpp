#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <climits>

using std::cout;
using std::endl;
using std::vector;
using std::min;
using std::abs;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// my solution 1 , runtime = 19 ms
class Solution1 {
public:
	void traverseBST(TreeNode* root) {
		if (root == nullptr) return;
		if (root->left) traverseBST(root->left);
		treeList.push_back(root->val);
		if (root->right) traverseBST(root->right);
	}

	int getMinimumDifference(TreeNode* root) {
		traverseBST(root);
		int minimum = abs(treeList[1] - treeList[0]);
		for (int i = 2; i < treeList.size(); ++i) {
			if (abs(treeList[i] - treeList[i - 1]) < minimum) {
				minimum = abs(treeList[i] - treeList[i - 1]);
			}
		}
		return minimum;
	}

private:
	vector<int> treeList;
};

// my solution 2 use std::min , runtime = 16 ms
class Solution {
public:
	void traverseBST(TreeNode* root) {
		if (root == nullptr) return;
		if (root->left) traverseBST(root->left);
		treeList.push_back(root->val);
		if (root->right) traverseBST(root->right);
	}

	int getMinimumDifference(TreeNode* root) {
		traverseBST(root);
		int minimum = abs(treeList[1] - treeList[0]);
		for (int i = 2; i < treeList.size(); ++i) {
			minimum = min(minimum, abs(treeList[i] - treeList[i - 1]));
		}
		return minimum;
	}

private:
	vector<int> treeList;
};

// my solution 3 concise funtion , runtime = 19 ms
class Solution3 {
public:
	int getMinimumDifference(TreeNode* root) {
		if (root->left) getMinimumDifference(root->left);
		minimum = min(minimum, abs(root->val - preElement));
		preElement = root->val;
		if (root->right) getMinimumDifference(root->right);
		return minimum;
	}

private:
	int preElement = pow(2, 31);
	int minimum = pow(2, 31);
};

// my perfect solution 4 , runtime = 19 ms
class Solution4 {
public:
	int getMinimumDifference(TreeNode* root) {
		if (root->left) getMinimumDifference(root->left);
		minimum = min(minimum, abs(root->val - preElement));
		preElement = root->val;
		if (root->right) getMinimumDifference(root->right);
		return minimum;
	}

private:
	int preElement = INT_MAX;
	int minimum = INT_MAX;
};

int main()
{
	system("pause");
	return 0;
}