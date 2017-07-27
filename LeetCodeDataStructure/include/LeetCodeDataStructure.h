#ifndef _LEETCODE_DATA_STRUCTURE_H_
#	define _LEETCODE_DATA_STRUCTURE_H_

#ifdef LEETCODE_DATA_STRUCTURE_DLL
#	define LEETCODE_EXP __declspec(dllexport)
#else 
#	define LEETCODE_EXP __declspec(dllimport)
#endif

// 禁用 warning C4251: “xxx::m_strTypeName”: class“std::basic_string<_Elem,_Traits,_Ax>”需要有 dll 接口由 class“xxx”的客户端使用。
// 问题的警告显示，参考博客 (http://blog.sina.com.cn/s/blog_4fc2fb600102y4mu.html)
#pragma warning(disable:4251)

#include <vector>
#include <string>

namespace LeetCode {
	// 结构定义
	class LEETCODE_EXP LCArray;				// 数组
	class LEETCODE_EXP LCSingleLinkedList;	// 单链表
	class LEETCODE_EXP LCBinaryTree;		// 二叉树

	// 二叉树叶子节点
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode * right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode() = default;
	};

	// 单链表节点
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode() = default;
	};
	
}

#endif