#include "LeetCodeDataStructure.h"

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

// 单链表
namespace LeetCode {

	class LEETCODE_EXP LCSingleLinkedList {
	public:
		// 构造：输入 "[1, 2, 3, 4]" 类型的字符串
		LCSingleLinkedList() = default;
		LCSingleLinkedList(std::string strInput);
		LCSingleLinkedList(const char* strInput);

		// 析构
		~LCSingleLinkedList();

		// 获取：单链表的根节点
		const ListNode* GetSingleLinkedListRoot() const;

		// 打印：单链表内容
		void PrintSingleLinkedList() const;

	private:
		// 构造：将字符串输入转化为单链表结构
		bool _ConstructSingleLinkedList(std::string strInput);

		// 构造：将 std::vector 转化为单链表
		bool _MakeSingleLinkedList(std::vector<int> vecSingleLinkedList);

	private:
		std::vector<ListNode> m_vecSingleLinkedList;
	};

}