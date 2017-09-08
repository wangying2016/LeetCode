#include <iostream>
#include <cstdlib>
#include <vector>

using std::vector;

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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0) return nullptr;
		int mid = nums.size() / 2;
		TreeNode *node = new TreeNode(nums[mid]);
		auto leftTree = vector<int>(nums.begin(), nums.begin() + mid);
		auto rightTree = vector<int>(nums.begin() + mid + 1, nums.end());
		if (mid != 0)
			node->left = sortedArrayToBST(leftTree);
		if (mid != nums.size() - 1)
			node->right = sortedArrayToBST(rightTree);
		return node;
	}
};

int main()
{
	return 0;
}