#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::min;

// my first solution1 , rutnime = 6 ms
class Solution1 {
public:
	string reverseStr(string s, int k) {
		int i = 0;
		for (; i < s.size(); i += k)
			if (i % (2 * k) == k) reverse(s.begin() + i - k, s.begin() + i);
		if (k >= s.size())
			reverse(s.begin(), s.end());
		else if (i % (2 * k) == k)
			reverse(s.begin() + i - k, s.end());
		return s;
	}
};

// my solutin 2 , runtime = 9 ms
class Solution2 {
public:
	string reverseStr(string s, int k) {
		int i = 2 * k;
		for (; i < s.size(); i += 2 * k)
			reverse(s.begin() + i - 2 * k, s.begin() + i - k);
		if (s.size() - (i - 2 * k) <= k)
			reverse(s.begin() + i - 2 * k, s.end());
		else
			reverse(s.begin() + i - 2 * k, s.begin() + i - k);
		return s;
	}
};

// my solution 3 , runtime = 6 ms
class Solution3 {
public:
	string reverseStr(string s, int k) {
		int i = 2 * k;
		for (; i < s.size(); i += 2 * k)
			reverse(s.begin() + i - 2 * k, s.begin() + i - k);
		if (s.size() % (2 * k) <= k && s.size() % (2 * k) != 0)
			reverse(s.begin() + i - 2 * k, s.end());
		else
			reverse(s.begin() + i - 2 * k, s.begin() + i - k);
		return s;
	}
};

// perfect solution 4 , runtime = 6 ms
class Solution4 {
public:
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += 2 * k) reverse(s.begin() + i, min(s.end(), s.begin() + i + k));
		return s;
	}
};

int main()
{
	string s = "abcdefg";
	int k = 2;
	Solution3 solution;
	cout << solution.reverseStr(s, k) << endl;
	system("pause");
	return 0;
}