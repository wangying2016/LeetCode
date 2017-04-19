#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::cout;
using std::endl;

// fail , Time Limit Exceeded
class Solution1 {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> result;
		for (int i = 1; i <= nums.size(); ++i) {
			auto it = find(nums.cbegin(), nums.cend(), i);
			if (it == nums.cend()) result.push_back(i);
		}
		return result;
	}
};

