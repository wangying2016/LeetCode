#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>

using std::vector;
using std::map;
using std::set;
using std::cout;
using std::endl;

// use std::map , runtime = 23 ms
class Solution1 {
public:
	int singleNumber(vector<int> &nums) {
		map<int, int> map;
		for (auto i : nums) ++map[i];
		for (auto j : map) if (j.second == 1) return j.first;
	}
};

// use std::set , runtime = 25 ms
class Solution2 {
public:
	int singleNumber(vector<int> &nums) {
		set<int> set;
		for (auto i : nums)
			if (set.find(i) == set.end()) set.insert(i);
			else set.erase(i);
			return *set.begin();
	}
};

// use xor , runtime = 13 ms
// For anyone who didn't understood why this works here is an explanation. This XOR operation works because it's like XORing all the numbers by itself.
// So if the array is{ 2,1,4,5,2,4,1 } then it will be like we are performing this operation
// ((2 ^ 2) ^ (1 ^ 1) ^ (4 ^ 4) ^ (5)) = > (0 ^ 0 ^ 0 ^ 5) = > 5.
// Hence picking the odd one out(5 in this case).

class Solution3 {
public:
	int singleNumber(vector<int> &nums) {
		int single = 0;
		for (auto i : nums) single ^= i;
		return single;
	}
};

int main()
{
	Solution3 solution3;
	vector<int> nums = { 1, 6, 1 };
	cout << solution3.singleNumber(nums) << endl;
	system("pause");
	return 0;
}