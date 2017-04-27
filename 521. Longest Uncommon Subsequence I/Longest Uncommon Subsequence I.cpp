#include <iostream>
#include <string>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;

// my solution , runtime = 3 ms
class Solution1 {
public:
	int findLUSlength(string a, string b) {
		bool isEqual = a.length() == b.length() ? true : false;
		if (!isEqual) 
			return a.length() > b.length() ? a.length() : b.length();
		else          
			return a == b ? -1 : a.length();
	}
};

// perfect solution , runtime = 3 ms
class Solution2 {
public:
	int findLUSlength(string a, string b) {
		return a == b ? -1 : (a.length() > b.length() ? a.length() : b.length());
	}
};

int main()
{
	Solution1 solution;
	cout << solution.findLUSlength("wang", "ying") << endl;
	system("pause");
	return 0;
}
