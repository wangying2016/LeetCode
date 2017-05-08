#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

// my solution use recursion , runtime = 3 ms
class Solution1 {
public:
	int addDigits(int num) {
		if (num < 10) return num;
		int sum = 0;
		do {
			sum += num % 10;
			num /= 10;
		} while (num != 0);
		return addDigits(sum);
	}
};

// my solution use loop , runtime = 3 ms
class Solution2 {
public:
	int addDigits(int num) {
		int sum = 0;
		while (true) {
			do {
				sum += num % 10;
				num /= 10;
			} while (num != 0);
			if (sum >= 10) num = sum, sum = 0;
			else           break;
		}
		return sum;
	}
};

// perfect solution use congruence formula , runtime = 9 ms
class Solution3 {
public:
	int addDigits(int num) {
		return 1 + (num - 1) % 9;
	}
};

int main()
{
	Solution1 solution1;
	Solution2 solution2;
	Solution3 solution3;
	cout << solution1.addDigits(38) << endl;
	cout << solution2.addDigits(38) << endl;
	cout << solution3.addDigits(38) << endl;
	system("pause");
	return 0;
}