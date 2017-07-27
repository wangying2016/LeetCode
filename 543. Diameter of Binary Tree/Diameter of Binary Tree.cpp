#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <set>
#include <utility>
#include <map>
#include <algorithm>
#include "LeetCodeDataStructure.h"
#include "LCBinaryTree.h"

using std::stack;
using std::vector;
using LeetCode::TreeNode;
using std::set;
using std::cout;
using std::endl;
using std::pair;
using std::map;
using std::max;

// my solution 1 , every node's left child tree's max depth add right child tree's max depth
// Time Limit Exceeded 
class Solution1 {
public:
	int diameterOfBinaryTree(TreeNode* root) {
		if (root == nullptr) return 0;
		int diameter = 0, temp = 0;
		temp = getNodeMaxLeftRightLength(root);
		if (root->left)
			diameterOfBinaryTree(root->left);
		if (root->right)
			diameterOfBinaryTree(root->right);
		diameter = temp > diameter ? temp : diameter;
		return diameter;
	}

private:
	int getNodeMaxLeftRightLength(TreeNode *node) {
		if (!node) return 0;
		std::vector<TreeNode*> stack;
		int count = 0, max_left = 0, max_right = 0;
		auto cur = node->left;
		if (cur != nullptr) {
			do {
				if (!stack.size() || stack.back()->val != cur->val) {
					++count;
					stack.push_back(cur);
				}
				if (cur->left)
					cur = cur->left;
				else if (cur->right)
					cur = cur->right;
				else {
					max_left = count > max_left ? count : max_left;
					stack.pop_back();
					--count;
					if (!stack.size()) break;
					if (stack.back()->left && stack.back()->left->val == cur->val)
						stack.back()->left = nullptr;
					else if (stack.back()->right)
						stack.back()->right = nullptr;
					cur = stack.back();
				}
			} while (cur != node);
		}

		cur = node->right;
		if (cur != nullptr) {
			do {
				if (!stack.size() || stack.back()->val != cur->val) {
					++count;
					stack.push_back(cur);
				}
				if (cur->left)
					cur = cur->left;
				else if (cur->right)
					cur = cur->right;
				else {
					max_right = count > max_right ? count : max_right;
					stack.pop_back();
					--count;
					if (!stack.size()) break;
					if (stack.back()->left && stack.back()->left->val == cur->val)
						stack.back()->left = nullptr;
					else if (stack.back()->right)
						stack.back()->right = nullptr;
					cur = stack.back();
				}
			} while (cur != node);
		}
		return max_left + max_right;
	}
};

// my solution 2, runtime error
class Solution2 {
public:
	int diameterOfBinaryTree(TreeNode *root) {
		if (!root) return 0;
		pair<int, int> count;
		if (root->left) count.first = root->left->val;
		if (root->right) count.second = root->right->val;
		mapBinaryTree[root->val] = count;
		diameterOfBinaryTree(root->left);
		diameterOfBinaryTree(root->right);
		int diameter = 0;
		for (auto node : mapBinaryTree) {
			int temp = diameterOfNode(node.first, mapBinaryTree);
			diameter = temp > diameter ? temp : diameter;
		}
		return diameter;
	}

	int diameterOfNode(int val, map<int, pair<int, int>> mapBinaryTree) {
		if (val == 0 || mapBinaryTree[val].first == 0 && mapBinaryTree[val].second == 0)
				return 1;
		return diameterOfNode(mapBinaryTree[val].first, mapBinaryTree) + diameterOfNode(mapBinaryTree[val].second, mapBinaryTree);
	}

private:
	map<int, pair<int, int>> mapBinaryTree;
};

// my solution 3 , runtime error
class Solution3 {
public:
	int diameterOfBinaryTree(TreeNode *root) {
		if (!root) return 0;
		countOfBinaryTree(root);
		int diameter = 0;
		for (auto node : mapBinaryTree) {
			int temp = diameterOfNode(node.first);
			diameter = temp > diameter ? temp : diameter;
		}
		return diameter;
	}

protected:
	void countOfBinaryTree(TreeNode *node) {
		if (!node) return;
		pair<int, int> temp;
		if (node->left) temp.first = node->left->val;
		if (node->right) temp.second = node->right->val;
		mapBinaryTree[node->val] = temp;
		countOfBinaryTree(node->left);
		countOfBinaryTree(node->right);
	}

	int diameterOfNode(int val) {
		if (val == 0 || mapBinaryTree[val].first == 0 && mapBinaryTree[val].second == 0)
			return 1;
		return diameterOfNode(mapBinaryTree[val].first) + diameterOfNode(mapBinaryTree[val].second);
	}

private:
	map<int, pair<int, int>> mapBinaryTree;
};

// my solution 4
// wrong answer
class Solution4 {
public:
	int diameterOfBinaryTree(TreeNode *root) {
		if (!root) return 0;
		countOfBinaryTree(root);
		cout << "traverse finished." << endl;
		int diameter = 0;
		for (auto node : mapBinaryTree) {
			cout << "node: " << node.first << " val: " << node.second.first << " " << node.second.second << endl;
		}

		for (auto node : mapBinaryTree) {
			int temp = diameterOfNode(node.first);
			diameter = temp > diameter ? temp : diameter;
			cout << "node: " << node.first << " diamteter: " << temp << endl;
		}
		return diameter;
	}

protected:
	void countOfBinaryTree(TreeNode *node) {
		if (!node) return;
		pair<int, int> temp;
		if (node->left) temp.first = node->left->val;
		if (node->right) temp.second = node->right->val;
		mapBinaryTree[node->val] = temp;
		countOfBinaryTree(node->left);
		countOfBinaryTree(node->right);
	}

	int diameterOfNode(int val) {
		int depth = 0;
		if (!mapBinaryTree[val].first && !mapBinaryTree[val].second) depth = 0;
		else depth = depthOfNode(mapBinaryTree[val].first) + depthOfNode(mapBinaryTree[val].second);
		cout << "node: " << val << " depth:" << depth << endl;
		return depth;
	}

	int depthOfNode(int val) {
		if (val == 0) return 0;
		else if (!mapBinaryTree[val].first && !mapBinaryTree[val].second) return 1;
		else return max(depthOfNode(mapBinaryTree[val].first), depthOfNode(mapBinaryTree[val].second)) + 1;
	}

private:
	map<int, pair<int, int>> mapBinaryTree;
};

// my solution 5 with detail comments , runtime = 52 ms
class Solution5 {
public:
	int diameterOfBinaryTree(TreeNode *root) {
		traverseBinaryTree(root);
		// output binary tree
		cout << "traverse binary tree begin:" << endl;
		for (auto i : list)
			cout << i->val << endl;
		cout << "traverse binary tree end." << endl;
		// output every node's sumary of max left depth and max right depth
		cout << "sumary of left and right max depth begin:" << endl;
		int diameter = 0;
		for (auto i : list) {
			int sumary = 0;
			sumary = depthOfNode(i->left) + depthOfNode(i->right);
			cout << "node:" << i->val << " sumary:" << sumary << endl;
			diameter = sumary > diameter ? sumary : diameter;
		}
		cout << "sumary of left and right max depth end." << endl;
		cout << "diameter is " << diameter << endl;
		return diameter;
	}

	void traverseBinaryTree(TreeNode *node) {
		if (!node) return;
		list.push_back(node);
		traverseBinaryTree(node->left);
		traverseBinaryTree(node->right);
	}

	int depthOfNode(TreeNode *node) {
		if (!node) return 0;
		return max(depthOfNode(node->left), depthOfNode(node->right)) + 1;
	}

private:
	vector<TreeNode*> list;
};

// my solution 6 , runtime = 26 ms
class Solution6 {
public:
	int diameterOfBinaryTree(TreeNode *root) {
		traverseBinaryTree(root);
		int diameter = 0;
		for (auto i : list) {
			int sumary = 0;
			sumary = depthOfNode(i->left) + depthOfNode(i->right);
			diameter = sumary > diameter ? sumary : diameter;
		}
		return diameter;
	}

	void traverseBinaryTree(TreeNode *node) {
		if (!node) return;
		list.push_back(node);
		traverseBinaryTree(node->left);
		traverseBinaryTree(node->right);
	}

	int depthOfNode(TreeNode *node) {
		if (!node) return 0;
		return max(depthOfNode(node->left), depthOfNode(node->right)) + 1;
	}

private:
	vector<TreeNode*> list;
};

// perfect solution , runtime = 26 ms
class Solution7 {
public:
	int diameterOfBinaryTree(TreeNode *root) {
		if (!root) return 0;
		int res = depthOfNode(root->left) + depthOfNode(root->right);
		return max(res, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
	}

	int depthOfNode(TreeNode *node) {
		if (!node) return 0;
		return max(depthOfNode(node->left), depthOfNode(node->right)) + 1;
	}
};

int main()
{
	LeetCode::LCBinaryTree lcBinaryTree("[1,2,null,3,null,4]");
	const LeetCode::TreeNode *root = lcBinaryTree.GetTreeBinaryTreeRoot();
	lcBinaryTree.PrintBinaryTree();
	Solution6 solution;
	cout << solution.diameterOfBinaryTree(const_cast<TreeNode*>(root)) << endl;
	system("pause");
	return 0;
}
 