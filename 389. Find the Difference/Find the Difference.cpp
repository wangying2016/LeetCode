#include <iostream>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::unordered_map;
using std::set;
using std::unordered_set;
using std::string;

// my solution 1 , runtime = 6 ms
class Solution1 {
public:
	char findTheDifference(string s, string t) {
		map<char, int> s_map;
		map<char, int> t_map;
		for (auto c : s) {
			++s_map[c];
		}
		for (auto c : t) {
			++t_map[c];
		}
		for (auto c : t) {
			if (t_map[c] != s_map[c]) {
				return c;
			}
		}
	}
};

// my solution 2 , runtime = 6 ms
class Solution2 {
public:
	char findTheDifference(string s, string t) {
		unordered_map<char, int> s_map;
		unordered_map<char, int> t_map;
		for (auto c : s) {
			++s_map[c];
		}
		for (auto c : t) {
			++t_map[c];
		}
		for (auto c : t) {
			if (t_map[c] != s_map[c]) {
				return c;
			}
		}
	}
};

// my solution 3 , falied
class Solution3 {
public:
	char findTheDifference(string s, string t) {
		unordered_set<char> s_set(s.cbegin(), s.cend());
		unordered_set<char> t_set(t.cbegin(), t.cend());
		int s_n = s_set.count('a');
		int t_n = t_set.count('a');
		for (auto c : t) {
			if (s_set.count(c) != t_set.count(c)) {
				return c;
			}
		}
	}
};

// my solution 4 , failed
// std::set::count or std::unordered_set::count 
// value only equals to 0 or 1
class Solution4 {
public:
	char findTheDifference(string s, string t) {
		set<char> s_set(s.cbegin(), s.cend());
		set<char> t_set(t.cbegin(), t.cend());
		for (auto c : t) {
			if (s_set.count(c) != t_set.count(c)) {
				return c;
			}
		}
	}
};

// my solution 5 , perfect runtime = 3 ms
class Solution5 {
public:
	char findTheDifference(string s, string t) {
		char c = '\0';
		for (auto s_c : s) {
			c ^= s_c;
		}
		for (auto t_c : t) {
			c ^= t_c;
		}
		return c;
	}
};

int main()
{
	Solution5 solution;
	cout << solution.findTheDifference("a", "aa") << endl;
	system("pause");
	return 0;
}