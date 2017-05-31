#include <iostream>
#include <cstdlib>
#include <string>

using std::cout;
using std::endl;
using std::string;

// my solution 1 , runtime = 6 ms
class Solution1 {
public:
	int titleToNumber(string s) {
		int result = 0;
		for (int i = 0; i < s.size(); ++i) {
			int temp = s[s.size() - 1 - i] - 'A' + 1;
			result += temp * pow(26, i);
		}
		return result;
	}
};

// my solution 2 , runtime = 6 ms
class Solution2 {
public:
	int titleToNumber(string s) {
		int result = 0, i = s.size() - 1;
		for (auto c : s) result += pow(26, i--) * (c - 'A' + 1);
		return result;
	}
};

int main()
{
	Solution2 solution;
	cout << solution.titleToNumber("AA") << endl;
	system("pause");
	return 0;
}