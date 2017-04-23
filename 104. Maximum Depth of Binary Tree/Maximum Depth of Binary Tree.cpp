#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::stack;
using std::vector;
using std::string;
using std::max_element;
using std::stoi;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode() = default;
};

// make Tree
class BinaryTree {
public:
	TreeNode* makeBinaryTree(vector<string> nodelist) {
		// 将形如 [1,null,2] 的字符串数组
		// 转化为 [1, -1, 2] 的整型数组
		// 以 -1 标记当前节点为空值
		vector<int> nodeData;
		for (auto str : nodelist) {
			if (str == "null") {
				nodeData.push_back(-1);
			} else {
				int node = stoi(str);
				nodeData.push_back(node);
			}
		}
		// 制造一个满足上述条件的树
		TreeNode *nodeHead = new TreeNode[nodeData.size()]();
		vector<TreeNode*> tree;
		TreeNode *q = nodeHead + nodeData.size();
		for (TreeNode *p = nodeHead; p < nodeHead + nodeData.size(); ++p) {
			if (nodeData[p - nodeHead] == -1) {
				p->left = nullptr;
				p->right = nullptr;
				p->val = 0;
			} else {
				// 左子结点为当前结点编号的 2 倍
				if (2 * (p - nodeHead + 1) <= nodeData.size()) {
					p->left = nodeHead + 2 * (p - nodeHead + 1) - 1;
				} else {
					p->left = nullptr;
				}
				// 右子结点为当前结点编号的 2 倍加 1
				if (2 * (p - nodeHead + 1) + 1 <= nodeData.size()) {
					p->right = nodeHead + 2 * (p - nodeHead + 1) - 1 + 1;
				} else {
					p->right = nullptr;
				}
				p->val = nodeData[p - nodeHead];
			}
			tree.push_back(p);
		}


		// test make tree is right or not
		vector<int> testTree;
		for (TreeNode *p = nodeHead; p < nodeHead + nodeData.size(); ++p) {
			testTree.push_back(p->val);
			int leftVal = 0;
			int rightVal = 0;
			if (p->left != nullptr) {
				leftVal = p->left->val;
			} 
			if (p->right != nullptr) {
				rightVal = p->right->val;
			}
			cout << "node " << p->val << " 's left child is " << leftVal <<
				" , right child is " << rightVal << endl;
		}

		return nodeHead;
	}
};

// my solution 1 , runtime = 9 ms
class Solution1 {
public:
	void countPath(TreeNode* root) {
		if (root != nullptr) {
			farthest_path.push(root->val);
		} else {
			farthest_count.push_back(farthest_path.size());
			return;
		}
		countPath(root->left);
		countPath(root->right);
		farthest_path.pop();
	}

	int maxDepth(TreeNode* root) {
		countPath(root);
		auto itMaxCount = max_element(farthest_count.begin(), farthest_count.end());
		if (itMaxCount == farthest_count.end()) return 0;
		else return *itMaxCount;
	}

private:
	stack<int> farthest_path;
	vector<int> farthest_count;
};

// my solution 2 , runtime = 6 ms
// remove the farthest_count , use only one max variable
class Solution2 {
public:
	void countPath(TreeNode* root) {
		if (root != nullptr) {
			farthest_path.push(root->val);
		} else {
			max = max > farthest_path.size() ? max : farthest_path.size();
			return;
		}	
		countPath(root->left);
		countPath(root->right);
		farthest_path.pop();
	}

	int maxDepth(TreeNode* root) {
		countPath(root);
		return max;
	}

private:
	int max;
	stack<int> farthest_path;
};

// my simplified solution , in one function
// no accept ， maybe the static variable's question
class Solution3 {
public:
	int maxDepth(TreeNode* root) {
		static int max;
		static stack<int> farthest_path;

		if (root != nullptr) {
			farthest_path.push(root->val);
		} else {
			max = max > farthest_path.size() ? max : farthest_path.size();
			return max;
		}
		maxDepth(root->left);
		maxDepth(root->right);
		farthest_path.pop();

		return max;
	}
};

// my simlified solution , move out static variable
// runtime = 6 ms
class Solution4 {
public:
	int maxDepth(TreeNode* root) {
		if (root != nullptr) {
			farthest_path.push(root->val);
		} else {
			max = max > farthest_path.size() ? max : farthest_path.size();
			return max;
		}
		maxDepth(root->left);
		maxDepth(root->right);
		farthest_path.pop();

		return max;
	}

private:
	int max;
	stack<int> farthest_path;
};

int main()
{
	/*vector<string> nodelist = { "1", "null", "2" };*/
	/*vector<string> nodelist = { "0", "0", "0", "0", "null", "null", "0", "null", "null", "null", "0" };*/
	vector<string> nodelist = { "1", "2", "3", "4", "null", "null", "7", "null", "null", "null", "11" };
	// 将指定的输入转换为二叉树结构
	BinaryTree binaryTree;
	TreeNode *nodeHead = binaryTree.makeBinaryTree(nodelist);
	// 计算二叉树的高度
	Solution4 solution3;
	cout << solution3.maxDepth(nodeHead) << endl;
	system("pause");
	return 0;
}