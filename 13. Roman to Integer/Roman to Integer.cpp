#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <string>

using std::cout;
using std::endl;
using std::unordered_map;
using std::string;

// my solution 1 , runtime = 86 s
class Solution1 {
public:
	int romanToInt(string s) {
		int sum = 0;
		unordered_map<char, int> roman;
		roman['I'] = 1;
		roman['V'] = 5;
		roman['X'] = 10;
		roman['L'] = 50;
		roman['C'] = 100;
		roman['D'] = 500;
		roman['M'] = 1000;
		for (int i = 0; i < s.size(); ++i) {
			sum += roman[s[i]];
			switch (s[i]) {
			case 'I':
			case 'X':
			case 'C':
				if (i + 1 < s.size() && roman[s[i + 1]] > roman[s[i]])
					sum -= 2 * roman[s[i]];
				break;
			}
		}
		return sum;
	}
};

// my solution 2 , runtime = 142 ms
class Solution2 {
public:
	int romanToInt(string s) {
		int sum = 0;
		unordered_map<char, int> roman = {
			{ 'I', 1 },{ 'V', 5 },{ 'X', 10 },{ 'L', 50 },{ 'C', 100 },{ 'D', 500 },{ 'M', 1000 }
		};
		for (int i = 0; i < s.size(); ++i) {
			sum += roman[s[i]];
			switch (s[i]) {
			case 'I':
			case 'X':
			case 'C':
				if (i + 1 < s.size() && roman[s[i + 1]] > roman[s[i]])
					sum -= 2 * roman[s[i]];
				break;
			}
		}
		return sum;
	}
};

// my solution 3 , runtime = 112 ms
class Solution3 {
public:
	int romanToInt(string s) {
		int sum = 0;
		unordered_map<char, int> roman = {
			{ 'I', 1 },{ 'V', 5 },{ 'X', 10 },{ 'L', 50 },{ 'C', 100 },{ 'D', 500 },{ 'M', 1000 }
		};
		for (int i = 0; i < s.size(); ++i) {
			sum += roman[s[i]];
			if (s[i] == 'I' || s[i] == 'X' || s[i] == 'C')
				if (i + 1 < s.size() && roman[s[i + 1]] > roman[s[i]])
					sum -= 2 * roman[s[i]];
		}
		return sum;
	}
};

int main()
{
	Solution1 solution;
	string s = "IV";
	cout << solution.romanToInt(s) << endl;
	system("pause");
	return 0;
}

