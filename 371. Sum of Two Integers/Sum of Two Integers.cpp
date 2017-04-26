#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

// error case : a = 20 , b = 30 
// my answer is 34 , expected answer is 50
class Solution1 {
public:
	int getSum(int a, int b) {
		long temp1 = a & b;
		temp1 <<= 1;
		long temp2 = a ^ b;
		return temp1 & temp2;
	}
};

// my solution , runtime = 0 ms
class Solution2 {
public:
	int getSum(int a, int b) {
		int temp = 0, sum = 0;
		do {
			sum = ((a & b) << 1) ^ (a ^ b);
			temp = (a & b) << 1;
			b = a ^ b;
			a = temp;
		} while (a & b);
		return sum;
	}
};

// perfect solution , runtime = 0 ms
class Solution3 {
public:
	int getSum(int a, int b) {
		int sum = a;
		while (b != 0) {
			sum = a ^ b;
			b = (a & b) << 1;
			a = sum;
		}
		return sum;
	}
};

int main()
{
	Solution2 solution;
	cout << solution.getSum(20, 30) << endl;
	system("pause");
	return 0;
}