#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>
#include <unordered_map>

using std::vector;
using std::cout;
using std::endl;
using std::stack;
using std::unordered_map;

// my solution
//class Solution {
//public:
//	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
//		vector<int> results;
//		for (auto findIt = findNums.cbegin(); findIt != findNums.cend(); ++findIt) {
//			int greaterNum = -1;
//			bool bFindSamePlace = false;
//			for (auto compareIt = nums.cbegin(); compareIt != nums.cend(); ++compareIt) {
//				if (*findIt == *compareIt) {
//					bFindSamePlace = true;
//					continue;
//				}
//				if (bFindSamePlace && *findIt < *compareIt) {
//					greaterNum = *compareIt;
//					break;
//				}
//			}
//			results.push_back(greaterNum);
//		}
//		return results;
//	}
//};

// perfect solution
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		stack<int> s;
		unordered_map<int, int> m;
		for (int n : nums) {
			while (s.size() && s.top() < n) {
				m[s.top()] = n;
				s.pop();
			}
			s.push(n);
		}
		vector<int> ans;
		for (int n : findNums) ans.push_back(m.count(n) ? m[n] : -1);
		return ans;
	}
};

int main()
{
	Solution solution;
	vector<int> findNums = { 4, 1 , 2 };
	vector<int> nums = { 1, 3, 4, 2 };
	vector<int> results = solution.nextGreaterElement(findNums, nums);
	for (auto item : results) {
		cout << item << endl;
	}
	system("pause");
	return 0;
}