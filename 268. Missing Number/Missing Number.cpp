#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort;

// my solution 1 , runtime = 39 ms
class Solution1 {
public:
	int missingNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i) {
			if (i != nums[i]) return i;
		}
		return nums[nums.size() - 1] + 1;
	}
};

// my solution 2 , runtime = 29 ms
// n ( n + 1) / 2
class Solution2 {
public:
	int missingNumber(vector<int>& nums) {
		int total = 0;
		for (auto i : nums) total += i;
		return nums.size() * (nums.size() + 1) / 2 - total;
	}
};

// my solution 3 , runtime = 23 ms
class Solution3 {
public:
	int missingNumber(vector<int>& nums) {
		int result = 0;
		for (int i = 0; i < nums.size() + 1; ++i) result ^= i;
		for (auto j : nums) result ^= j;
		return result;
	}
};

// my solution 4 , runtime = 26 ms
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int result = 0;
		for (int i = 0; i < nums.size(); ++i) {
			result ^= nums[i];
			result ^= i;
		}
		return result ^= nums.size();
	}
};

int main()
{
	vector<int> nums = { 0, 1, 3 };
	Solution1 solution;
	cout << solution.missingNumber(nums) << endl;
	system("pause");
	return 0;
}