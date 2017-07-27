#include "LeetCodeDataStructure.h"

// LeetCode's Binary Tree Definition
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

// 二叉树
namespace LeetCode {

	class LEETCODE_EXP LCBinaryTree {
	public:
		// 构造：输入 "[1, null, 2]" 类型的字符串
		LCBinaryTree() = default;
		LCBinaryTree(std::string strInput);
		LCBinaryTree(const char* strInput);

		// 析构
		~LCBinaryTree();

		// 获取：二叉树的根节点
		const TreeNode* GetTreeBinaryTreeRoot() const;

		// 打印：二叉树内容
		void PrintBinaryTree() const;

	private:
		// 构造：将字符串输入转化为二叉树结构
		bool _ConstructBinaryTree(std::string strInput);

		// 构造：将 std::vector 转化为二叉树
		bool _MakeBinaryTree(std::vector<int> vecBinaryTree);

		// 定义：二叉树节点方向
		enum EPrintDirection {
			EPrintDirection_Left = 0,
			EPrintDirection_Right,
			EPrintDirection_Root,
		};

		// 打印：打印一个节点
		void _PrintTreeNode(const TreeNode node, int depth, enum EPrintDirection eDirection) const;

	private:
		std::vector<TreeNode> m_vecBinaryTree; 
	};

}