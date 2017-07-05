#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::unordered_map;

// my solution 1 , runtime = 6 ms
// without follow up
class Solution1 {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> results;
		map<int, int> count1, count2;
		for (auto i : nums1) count1[i]++;
		for (auto j : nums2) count2[j]++;
		for (auto item1 : count1)
			if (count2.find(item1.first) != count2.end()) {
				int intersection = item1.second > count2[item1.first] ? count2[item1.first] : item1.second;
				while (intersection--) results.push_back(item1.first);
			}
		return results;
	}
};

// my solution 2 
// What if the given array is already sorted ? How would you optimize your algorithm ?
class Solution2 {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> results;
		int a = 0, b = 0;
		while (a < nums1.size() && b < nums2.size()) {
			if (nums1[a] > nums2[b]) ++b;
			if (nums1[a] < nums2[b]) ++a;
			if (nums1[a] == nums2[b]) {
				results.push_back(nums1[a]);
				a++;
				b++;
			}
		}
		return results;
	}
};

// What if nums1's size is small compared to nums2's size ? Whitch algorithm is better ?
// solution 2 , first sorted

// What if elements of nums2 are stored on disk , and the memory is limited such that you cannaot
// load all elements into the memory at once?
// solution 1 , get some nums2's elements to seach them in nums1's map

// my solution3 , runtime = 12 ms
class Solution3 {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> results;
		unordered_map<int, int> count1, count2;
		for (auto i : nums1) count1[i]++;
		for (auto j : nums2)
			if (--count1[j] >= 0) results.push_back(j);
		return results;
	}
};

int main()
{
	Solution1 solution;
	vector<int> nums1 = { 1, 2, 2, 1 };
	vector<int> nums2 = { 2, 2 };
	vector<int> results = solution.intersect(nums1, nums2);
	for (auto i : results)
		cout << i << endl;
	system("pause");
	return 0;
}