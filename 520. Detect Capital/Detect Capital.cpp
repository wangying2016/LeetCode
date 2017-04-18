#include <iostream>
#include <string>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;

// my solution1 , runtime = 12 ms
class Solution1 {
public:
	bool detectCapitalUse(string word) {
		if (word.size() == 1) return true;
		if (islower(word[0])) {
			for (auto i : word) {
				if (isupper(i)) return false;
			}
			return true;
		} else {
			bool isNotAllLower = false;
			bool isNotAllUpper = false;
			for (size_t i = 0; i < word.size(); ++i) {
				if (islower(word[i])) isNotAllUpper = true;
				else isNotAllLower = true;
			}
			if (isNotAllLower && isNotAllUpper) return false;
			else return true;
		}
	}
};

// my solution2, runtime = 9 ms
class Solution2 {
public:
	bool detectCapitalUse(string word) {
		if (word.size() == 1) return true;
		if (islower(word[0])) {
			for (auto i : word)
				if (isupper(i)) return false;
			return true;
		} else {
			bool hasUpper = false;
			bool hasLower = false;
			for (size_t i = 1; i < word.size(); ++i) {
				if (islower(word[i])) hasLower = true;
				else hasUpper = true;
			}
			if (hasUpper && hasLower) return false;
			else return true;
		}
	}
};

// other's solution , runtime = 9 ms
class Solution3 {
public:
	bool detectCapitalUse(string word) {
		int count = 0;
		for (auto i : word) if (isupper(i)) ++count;
		return !count || count == word.size() || isupper(word[0]) && count == 1;
	}
};

int main()
{
	Solution1 solution1;
	string word = "fffffffffffffffffffffffF";
	cout << solution1.detectCapitalUse(word) << endl;
	system("pause");
	return 0;
}