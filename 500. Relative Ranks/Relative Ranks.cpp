#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::greater;
using std::sort;
using std::to_string;

// my solution 1 , runtime = 19 ms
class Solution1 {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		vector<int> original(nums);
		map<int, int> num_rank;
		vector<string> result;
		sort(nums.begin(), nums.end(), greater<int>());
		for (int i = 0; i < nums.size(); ++i) num_rank[nums[i]] = i;
		for (int j = 0; j < original.size(); ++j) {
			if (num_rank[original[j]] == 0) result.push_back("Gold Medal");
			else if (num_rank[original[j]] == 1) result.push_back("Silver Medal");
			else if (num_rank[original[j]] == 2) result.push_back("Bronze Medal");
			else    result.push_back(to_string(num_rank[original[j]] + 1));
		}
		return result;
	}
};

// my solution 2 use two map , runtime = 29 ms
class Solution2 {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		map<int, int> pos;
		map<int, int> rank;
		vector<string> result;
		for (int i = 0; i < nums.size(); ++i) pos[i] = nums[i];
		sort(nums.begin(), nums.end(), greater<int>());
		for (int j = 0; j < nums.size(); ++j) rank[nums[j]] = j;
		for (int z = 0; z < nums.size(); ++z) {
			if (rank[pos[z]] == 0) result.push_back("Gold Medal");
			else if (rank[pos[z]] == 1) result.push_back("Silver Medal");
			else if (rank[pos[z]] == 2) result.push_back("Bronze Medal");
			else result.push_back(to_string(rank[pos[z]] + 1));
		}
		return result;
	}
};

int main()
{
	Solution1 solution1;
	vector<int> nums = { 1, 2, 3 };
	vector<string> result = solution1.findRelativeRanks(nums);
	for (auto str : result) {
		cout << str << endl;
	}
	system("pause");
	return 0;
}
