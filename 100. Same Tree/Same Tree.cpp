#include <iostream>
#include <cstdlib>
#include <queue>

using std::cout;
using std::endl;
using std::queue;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// my solution 1 , runtime = 3 ms
class Solution1 {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) return true;
		if (p == nullptr || q == nullptr || p->val != q->val) return false;
		if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
			return true;
		} else {
			return false;
		}
	}
};

// my solution 2 more concise , runtime = 0 ms
class Solution2 {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) return true;
		if (p == nullptr || q == nullptr) return false;
		if (p->val != q->val) return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

// a little funny solution , runtime = 3 ms
class Solution3 {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) return true;
		if (p == NULL || q == NULL) return false;

		TreeNode *curp = NULL, *curq = NULL;

		queue<TreeNode *>qp;
		queue<TreeNode *>qq;
		qp.push(p);
		qq.push(q);

		while (!qp.empty() && !qq.empty())
		{
			curp = qp.front();
			qp.pop();
			curq = qq.front();
			qq.pop();

			if (curp == NULL && curq == NULL)
				continue;
			if (curp && curq)
			{
				if (curp->val != curq->val) return false;
				qp.push(curp->left);
				qp.push(curp->right);
				qq.push(curq->left);
				qq.push(curq->right);
			} else
				return false;
		}
		if (qp.empty() && qq.empty())
			return true;

		return false;
	}
};

int main()
{
	system("pause");
	return 0;
}