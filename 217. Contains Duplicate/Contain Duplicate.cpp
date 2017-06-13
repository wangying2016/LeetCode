#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <algorithm>


using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::set;
using std::sort;
using std::unique;

// my solution 1 , runtime = 59 ms
class Solution1 {
public:
	bool containsDuplicate(vector<int>& nums) {
		map<int, int> num_count;
		for (auto i : nums) if (++num_count[i] > 1) return true;
		return false;
	}
};

// my solution 2 , runtime = 49 ms
class Solution2 {
public:
	bool containsDuplicate(vector<int>& nums) {
		set<int> num_set;
		for (auto i : nums)
			if (num_set.find(i) != num_set.end()) return true;
			else num_set.insert(i);
		return false;
	}
};

// my solution 3, runtime = 32 ms
class Solution3 {
public:
	bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return unique(nums.begin(), nums.end()) != nums.end();
	}
};

// perfect solution only one line , runtime 36 ms
class Solution4 {
public:
	bool containsDuplicate(vector<int>& nums) {
		return set<int>(nums.begin(), nums.end()).size() < nums.size();
	}
};

int main()
{
	Solution3 solution;
	vector<int> nums = { 1, 2, 3, 1 };
	bool b = solution.containsDuplicate(nums);
	system("pause");
	return 0;
}