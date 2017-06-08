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

// my solution 1 , runtime = 19 ms
class Solution1 {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> char_count;
		int sum_double = 0, max_single = 0;
		char single_char = '\0';
		for (auto c : s) ++char_count[c];
		for (auto item : char_count)
			if (item.second % 2 && item.second > max_single) {
				max_single = item.second;
				single_char = item.first;
			}
		for (auto item : char_count)
			if (item.first != single_char)
				sum_double += item.second % 2 ? item.second - 1 : item.second;
		return sum_double + max_single;
	}
};

// my solution 2 , runtime = 9 ms
class Solution2 {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> char_count;
		int sum = 0;
		bool bHasSingleChar = false;
		for (auto c : s) ++char_count[c];
		for (auto item : char_count) {
			if (item.second % 2) bHasSingleChar = true;
			sum += item.second % 2 ? item.second - 1 : item.second;
		}
		return bHasSingleChar ? sum + 1 : sum;
	}
};

// my solution 3 , runtime = 6 ms
class Solution3 {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> char_count;
		int sum = 0, single = 0;
		for (auto c : s) ++char_count[c];
		for (auto item : char_count) {
			sum += item.second;
			if (item.second % 2) ++single;
		}
		return single ? sum - single + 1 : sum;
	}
};

// my solution 4 , runtime = 6 ms
class Solution {
public:
	int longestPalindrome(string s) {
		int sum = s.size(), single = 0, temp = 0;
		sort(s.begin(), s.end());
		for (auto c : s)
			if (temp == c) temp = 0, --single;
			else temp = c, ++single;
			return single ? sum - single + 1 : sum;
	}
};

int main()
{

	system("pause");
	return 0;
}