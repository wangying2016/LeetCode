#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>

using std::cout;
using std::endl;
using std::swap;
using std::vector;

// my solution 1 , failed 
class Solution1 {
public:
	void moveZeroes(vector<int>& nums) {
		int low = 0, high = nums.size() - 1;
		while (low < high) {
			while (nums[low] != 0) ++low;
			while (nums[high] == 0) --high;
			swap(nums[low++], nums[high--]);
		}
	}
};

// my solution2 , Runtime Error Message:malloc() : memory corruption : 0x0000000000f161b0 * **
class Solution2 {
public:
	void moveZeroes(vector<int>& nums) {
		int zero = 0, non_zero = 0;
		while (zero < nums.size() && non_zero < nums.size()) {
			while (nums[zero] != 0) ++zero;
			while (nums[non_zero] == 0) ++non_zero;
			swap(nums[zero++], nums[non_zero++]);
		}
	}
};

// my solution3 , runtime = 16 ms
class Solution3 {
public:
	void moveZeroes(vector<int>& nums) {
		int zero = 0, non_zero = 0;
		while (true) {
			while (zero < nums.size() && nums[zero] != 0) ++zero;
			while (non_zero < nums.size() && nums[non_zero] == 0) ++non_zero;
			if (zero == nums.size() || non_zero == nums.size()) break;
			if (zero < non_zero) swap(nums[zero++], nums[non_zero++]);
			else ++non_zero;
		}
	}
};

// perfect sulution , runtime = 16 ms
class Solution4 {
public:
	void moveZeroes(vector<int>& nums) {
		int j = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != 0) {
				nums[j++] = nums[i];
			}
		}
		for (; j < nums.size(); ++j) {
			nums[j] = 0;
		}
	}
};

int main()
{
	vector<int> nums = { 1, 0, 1};
	Solution1 solution1;
	Solution2 solution2;
	Solution3 solution3;
	Solution4 solution4;
	// solution1.moveZeroes(nums);
	// solution2.moveZeroes(nums);
	// solution3.moveZeroes(nums);
	solution4.moveZeroes(nums);
	for (auto i : nums) {
		cout << i << endl;
	}
	system("pause");
	return 0;
}