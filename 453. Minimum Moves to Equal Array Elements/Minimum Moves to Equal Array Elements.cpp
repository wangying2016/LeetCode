#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::max_element;
using std::min_element;
using std::distance;

// my solution 1 , runtime error , error case [1,2147483647]
class Solution1 {
public:
	int minMoves(vector<int>& nums) {
		auto maxIt = max_element(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i) {
			if (i != distance(nums.begin(), maxIt)) ++nums[i];
		}
		maxIt = max_element(nums.begin(), nums.end());
		auto minIt = min_element(nums.begin(), nums.end());
		++count;
		if (*maxIt == *minIt) return count;
		else return minMoves(nums);
	}

private:
	int count = 0;
};

// my solution 2 , runtime error , error case [-2147483648,-2147483647]
class Solution2 {
public:
	int minMoves(vector<int>& nums) {
		auto maxIt = max_element(nums.begin(), nums.end());
		int max_second = 0;
		for (auto item : nums)
			if (item != *maxIt && item > max_second) max_second = item;
		int distance = *maxIt - max_second == 0 ? 1 : *maxIt - max_second;
		*maxIt - max_second == 0 ? count : count += *maxIt - max_second;
		for (int i = 0; i < nums.size(); ++i) {
			if (i != std::distance(nums.begin(), maxIt)) nums[i] += distance;
		}
		maxIt = max_element(nums.begin(), nums.end());
		auto minIt = min_element(nums.begin(), nums.end());
		if (*maxIt == *minIt) return count;
		else return minMoves(nums);
	}

private:
	int count = 0;
};

int main()
{
	/*vector<int> nums = { 1, 2, 3 };*/
	vector<int> nums = { -2147483648, -2147483647 };
	Solution2 solution;
	cout << solution.minMoves(nums) << endl;
	system("pause");
	return 0;
}