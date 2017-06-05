#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::unordered_map;
using std::vector;

// my solution 1 , runtime = 19 ms
class Solution1 {
public:
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> appear_count;
		int max = 0, result = 0;
		for (auto i : nums) ++appear_count[i];
		for (auto item : appear_count)
			if (max < item.second) {
				max = item.second;
				result = item.first;
			}
		return result;
	}
};

// my solution 2 , runtime = 29 ms
class Solution2 {
public:
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> appear_count;
		for (auto i : nums) {
			if (appear_count[i] < nums.size() / 2) ++appear_count[i];
			else return i;
		}
	}
};

// my solution 3 , runtime = 22 ms
class Solution3 {
public:
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> appear_count;
		for (auto i : nums)
			if (++appear_count[i] > nums.size() / 2)
				return i;
	}
};

// most posts answer , runtime = 19 ms
class Solution4 {
public:
	int majorityElement(vector<int>& nums) {
		int majority = nums[0], count = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (count == 0) {
				count++;
				majority = nums[i];
			} else if (majority == nums[i]) {
				count++;
			} else count--;
		}
		return majority;
	}
};

int main()
{
	system("pause");
	return 0;
}