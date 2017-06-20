#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::queue;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// my solution 1 iteratively change value , runtime = 9 ms
class Solution1 {
public:
	ListNode* reverseList(ListNode* head) {
		vector<int> value;
		for (auto p = head; p != nullptr; p = p->next)
			value.push_back(p->val);
		int i = 0;
		for (auto p = head; p != nullptr; p = p->next, ++i)
			p->val = value[value.size() - i - 1];
		return head;
	}
};

// my solution 2 recursively change value , runtime = 9 ms
class Solution2 {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr) return head;
		value.push(head->val);
		reverseList(head->next);
		head->val = value.front();
		value.pop();
		return head;
	}

private:
	queue<int> value;
};

// my solution 3 iteratively change structure , runtime = 9 ms
class Solution3 {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *pre = nullptr;
		while (head != nullptr) {
			auto temp = head->next;
			head->next = pre;
			pre = head;
			head = temp;
		}
		return pre;
	}
};

// my solution 4 recursively change structure , runtime = 6 ms
class Solution4 {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr) return head;
		if (head->next == nullptr) return head;
		auto newHead = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return newHead;
	}
};

int main()
{
	Solution1 solution;
	system("pause");
	return 0;
}