#include <iostream>
#include <cstdlib>


// Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// my first solution 1 , runtime = 13 ms
class Solution1 {
public:
	void deleteNode(ListNode* node) {
		ListNode *pre = nullptr;
		ListNode *cur = node;
		while (cur->next != nullptr) {
			cur->val = cur->next->val;
			pre = cur;
			cur = cur->next;
		}
		pre->next = nullptr;
		delete cur;
	}
};

// my second solution 2 , runtime = 13 ms
class Solution2 {
public:
	void deleteNode(ListNode* node) {
		ListNode *pre = nullptr;
		ListNode *cur = node;
		for (; cur->next; pre = cur, cur = cur->next)
			cur->val = cur->next->val;
		pre->next = nullptr;
		delete cur;
	}
};

// perfect soluiton 3 , runtime = 13 ms
class Solution3 {
public:
	void deleteNode(ListNode* node) {
		if (node == nullptr) return;
		ListNode *temp = node->next;
		node->val = temp->val;
		node->next = temp->next;
		delete temp;
	}
};

int main()
{
	return 0;
}