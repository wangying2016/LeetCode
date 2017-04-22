#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;

// my solution
class Solution1 {
public:
	bool canWinNim(int n) {
		if (n % 4 == 0) return false;
		else return true;
	}
};

// other's solution
class Solution2 {
public:
	bool canWinNim(int n) {
		return n % 4;
	}
};

int main()
{
	Solution1 solution;
	int n = 0;
	cin >> n;
	cout << solution.canWinNim(n) << endl;
	system("pause");
	return 0;
}