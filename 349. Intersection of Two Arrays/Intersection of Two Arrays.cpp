#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::unordered_set;
using std::sort;

// my solution use two set , runtime = 13 ms
class Solution1 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> set1(nums1.begin(), nums1.end());
		set<int> set2(nums2.begin(), nums2.end());
		vector<int> result;
		for (auto i : set1) 
			if (set2.find(i) != set2.end()) result.push_back(i);
		return result;
	}
};

// other's solution use sort and two pointers , runtime = 6 ms
class Solution2 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size(), m = nums2.size();
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int i = 0, j = 0;
		vector<int> res;
		while (i < n && j < m) {
			if (nums1[i] < nums2[j]) i++;
			else if (nums1[i] > nums2[j]) j++;
			else {
				if (res.empty() || nums1[i] != res[res.size() - 1]) res.push_back(nums1[i]);
				i++; j++;
			}
		}
		return res;
	}
};

// other's solution use unordered_set , runtime = 6 ms
class Solution3 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> m(nums1.begin(), nums1.end());
		vector<int> res;
		for (auto a : nums2)
			if (m.count(a)) {
				res.push_back(a);
				m.erase(a);
			}
		return res;
	}
};

int main()
{
	vector<int> nums1 = { 1, 2, 2, 1 };
	vector<int> nums2 = { 1, 2 };
	Solution1 solution;
	for (auto i : solution.intersection(nums1, nums2)) {
		cout << i << endl;
	}
	system("pause");
	return 0;
}
