#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::cout;
using std::endl;

class MySolution {
public:
	int findMaxConsecutiveOnes(vector<int> &nums) {
		int temp = 0, max = 0;
		for (auto i : nums) {
			if (i) {
				++temp;
				if (temp > max) max = temp;
			} 
			else  temp = 0;
		}
		return max;
	}
};

class OtherSolution {
public:
	int findMaxConsecutiveOnes(vector<int> &nums) {
		int temp = 0, max = 0;
		for (auto i : nums) {
			if (i) max = ++temp > max ? temp : max;
			else temp = 0;
		}
		return max;
	}
};

int main()
{
	vector<int> nums = { 1, 1, 1, 0, 1, 1 };
	MySolution mysolution;
	std::cout << mysolution.findMaxConsecutiveOnes(nums) << std::endl;
	system("pause");
	return 0;
}