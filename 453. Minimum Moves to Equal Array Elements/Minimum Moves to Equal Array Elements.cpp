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

// my solution 1 , Compile Error
class Solution1 {
public:
	int minMoves(vector<int>& nums) {
		auto min = min_element(nums.begin(), nums.end());
		auto max = max_element(nums.begin(), nums.end());
		if (*min == *max) return count;
		for (int i = 0; i < nums.size(); ++i) {
			if (max - nums.begin() != i) ++nums[i];
		}
		++count;
		return minMoves(nums);
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

// my solution 3 , runtime error , error case 
// [83,-14,77,15,93,35,86,-8,-51,-79,62,-73,-10,-41,63,26,40,-74,72,36,-89,68,67,-71,82,30,-38,23,-33,35,29,-98,-78,-42...
class Solution3 {
public:
	int minMoves(vector<int>& nums) {
		auto max = max_element(nums.begin(), nums.end());
		auto min = min_element(nums.begin(), nums.end());
		if (*max == *min) return count;
		int maxTemp = *max;
		*max = INT_MIN;
		auto max_second = max_element(nums.begin(), nums.end());
		*max = maxTemp;
		int distance = *max - *max_second == 0 ? 1 : *max - *max_second;
		count += distance;
		for (int i = 0; i < nums.size(); ++i) {
			if (max - nums.begin() != i) nums[i] += distance;
		}
		return minMoves(nums);
	}

private:
	int count = 0;
};

// perfect solution , runtime = 52 ms
class Solution4 {
public:
	int minMoves(vector<int>& nums) {
		int sum = 0, moves = 0;
		auto minIt = min_element(nums.begin(), nums.end());
		for (auto i : nums) sum += i;
		return sum - *minIt * nums.size();
	}
};

// another perfect solution , runtime = 53 ms
class Solution5 {
public:
	int minMoves(vector<int>& nums) {
		int moves = 0;
		auto minIt = min_element(nums.begin(), nums.end());
		for (auto i : nums) moves += i - *minIt;
		return moves;
	}
};


int main()
{
	vector<int> nums = { 1, 2, 3 };
	Solution5 solution;
	cout << solution.minMoves(nums) << endl;
	system("pause");
	return 0;
}