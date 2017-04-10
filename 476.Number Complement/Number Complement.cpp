#include <iostream>
#include <stdlib.h>
#include <cmath>

// my solution
//class Solution {
//public:
//	int findComplement(int num) {
//		int value = 0;
//		for (int i = 0; num != 0; ++i) {
//			if (num % 2 == 0) {
//				value += pow(2, i);
//			}
//			num /= 2;
//		}
//		return value;
//	}
//};

// perfect solution
class Solution {
public:
	int findComplement(int num) {
		unsigned mask = ~0;
		while (num & mask) mask <<= 1;
		return ~num & ~mask;
	}
};

int main()
{
	int num = 0;
	std::cin >> num;
	Solution solution;
	std::cout << num << "'s complement number is " << solution.findComplement(num)
		<< std::endl;
	system("pause");
	return 0;
}

