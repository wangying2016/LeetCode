#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_set>
#include <set>
#include <algorithm>

using std::vector;
using std::unordered_set;
using std::set;
using std::abs;
using std::sort;
using std::unique;
using std::cout;
using std::endl;

// my solution , runtime = 222 ms
class Solution1 {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> result;
		set<int> nums_set(nums.begin(), nums.end());
		for (int i = 1; i <= nums.size(); ++i) {
			if (nums_set.find(i) == nums_set.end()) {
				result.push_back(i);
			}
		}
		return result;
	}
};

// replace set to unordered_set , runtime = 162 ms
class Solution2 {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> result;
		unordered_set<int> nums_set(nums.begin(), nums.end());
		for (int i = 1; i <= nums.size(); ++i) {
			if (nums_set.find(i) == nums_set.end()) {
				result.push_back(i);
			}
		}
		return result;
	}
};

// no use array attribute , runtime = 762 ms
class Solution3 {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		for (auto i : nums) {
			if (i % nums.size() == 0) {
				nums[nums.size() - 1] += nums.size();
			} else {
				nums[i % nums.size() - 1] += nums.size();
			}
		}
		for (auto it = nums.begin(); it != nums.end(); ++it) {
			if (*it <= nums.size()) {
				*it = it - nums.begin() + 1;
			}
		}
		for (auto it = nums.begin(); it != nums.end(); ++it) {
			if (*it > nums.capacity()) {
				it = nums.erase(it);
				--it;
			}
		}
		return nums;
	}
};

// in order to reduce runtime , runtime = 132 ms
class Solution4 {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> result;
		for (auto i : nums) {
			if (i % nums.size() == 0) {
				nums[nums.size() - 1] += nums.size();
			} else {
				nums[i % nums.size() - 1] += nums.size();
			}
		}
		for (auto it = nums.begin(); it != nums.end(); ++it) {
			if (*it <= nums.size()) {
				result.push_back(it - nums.begin() + 1);
			}
		}
		return result;
	}
};

// perfect solution , runtime = 138 ms
class Solution5 {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> result;
		for (auto i : nums) {
			i = abs(i);
			nums[i - 1] = -abs(nums[i - 1]);
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > 0) {
				result.push_back(i + 1);
			}
		}
		return result;
	}
};

int main()
{
	Solution5 solution5;
	// [4,3,2,7,7,2,3,1]
	/*vector<int> nums = { 4, 3, 2, 7, 8, 2, 3, 1 };*/
	/*vector<int> nums = { 4, 3, 2, 7, 7, 2, 3, 1 };*/
	// [10,2,5,10,9,1,1,4,3,7]
	/*vector<int> nums = { 10, 2, 5, 10, 9, 1, 1, 4, 3, 7 };*/
	// [5, 4, 6, 7, 9, 3, 10, 9, 5, 6]
	vector<int> nums = { 5, 4, 6, 7, 9, 3, 10, 9, 5, 6 };
	vector<int> result = solution5.findDisappearedNumbers(nums);
	for (auto i : result) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}