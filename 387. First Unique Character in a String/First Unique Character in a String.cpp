#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::pair;
using std::min;

// my first solution , runtime = 76 ms
class Solution1 {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int> char_map;
		char unique = '\0';
		for (auto c : s) ++char_map[c];
		for (auto c : s)
			if (char_map[c] == 1) {
				unique = c;
				break;
			}
		return s.find(unique);
	}
};

// my second solution , runtime = 86 ms
class Solution2 {
public:
	int firstUniqChar(string s) {
		unordered_map<int, pair<int, int>> char_map;
		int index = s.size();
		for (int i = 0; i < s.size(); ++i) {
			char_map[s[i]].first++;
			char_map[s[i]].second = i;
		}
		for (auto item : char_map) {
			if (item.second.first == 1) {
				index = min(index, item.second.second);
			}
		}
		return index == s.size() ? -1 : index;
	}
};

int main()
{
	Solution1 solution;
	cout << solution.firstUniqChar("leetcode") << endl;
	system("pause");
	return 0;
}