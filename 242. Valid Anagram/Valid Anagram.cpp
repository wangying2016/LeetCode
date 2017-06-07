#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::unordered_map;
using std::string;
using std::sort;
using std::wstring;

// my solution 1 use unordered map , runtime = 16 ms
class Solution1 {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		unordered_map<char, int> s_map, t_map;
		for (auto c : s) s_map[c]++;
		for (auto c : t) t_map[c]++;
		for (auto s_item : s_map)
			if (t_map[s_item.first] != s_item.second)
				return false;
		return true;
	}
};

// my solution 2 use sort , runtime = 22 ms
class Solution2 {
public:
	bool isAnagram(string s, string t) {
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}
};

// my solution 3 for unicode characters 
class Solution3 {
public:
	bool isAnagram(wstring s, wstring t) {
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}
};

// my solution 4 for unicode characters
class Solution4 {
public:
	bool isAnagram(wstring s, wstring t) {
		if (s.size() != t.size()) return false;
		unordered_map<char, int> s_map, t_map;
		for (auto c : s) s_map[c]++;
		for (auto c : t) t_map[c]++;
		for (auto s_item : s_map)
			if (t_map[s_item.first] != s_item.second)
				return false;
		return true;
	}
};

int main()
{
	wstring s = L"ÄãºÃ";
	wstring t = L"ºÃÄã";
	Solution4 solution;
	cout << solution.isAnagram(s, t) << endl;
	system("pause");
	return 0;
}