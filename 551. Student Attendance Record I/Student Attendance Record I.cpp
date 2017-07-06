#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <regex>

using std::cout;
using std::endl;
using std::string;
using std::stack;
using std::regex;
using std::regex_search;

// my first soluton , runtime = 6 ms 
class Solution1 {
public:
	bool checkRecord(string s) {
		stack<char> a, l;
		for (auto i : s) {
			if (i == 'A') {
				if (a.size() == 1) return false;
				else a.push(i);
			}
			if (i == 'L') {
				if (l.size() == 2) return false;
				else l.push(i);
			}
			else while (l.size()) l.pop();
		}
		return true;
	}
};

// my solution 2 , runtime = 3 ms
class Solution2 {
public:
	bool checkRecord(string s) {
		bool hasA = false;
		int countL = 0;
		for (auto i : s) {
			if (i == 'A') {
				if (hasA) return false;
				else hasA = true;
			}
			if (i == 'L') {
				if (countL == 2) return false;
				else countL++;
			}
			else countL = 0;
		}
		return true;
	}
};

// my solution 3 , runtime = 3 ms
class Solution3 {
public:
	bool checkRecord(string s) {
		int a = 0, l = 0;
		for (auto i : s) {
			if (i == 'A') a++;
			if (i == 'L') l++;
			else l = 0;
			if (a > 1 || l > 2) return false;
		}
		return true;
	}
};

// perfect solution 4 , runtime = 6 ms
class Solution {
public:
	bool checkRecord(string s) {
		return !regex_search(s, regex("A.*A|LLL"));
	}
};

int main()
{
	Solution1 solution;
	string s = "LLPLL";
	cout << solution.checkRecord(s) << endl;
	system("pause");
	return 0;
}

