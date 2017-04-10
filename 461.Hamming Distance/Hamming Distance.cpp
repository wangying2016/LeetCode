#include <iostream>
#include <stdlib.h>

class Solution {
public:
	int hammingDistance(int x, int y) {
		int tempX = x;
		int tempY = y;
		int distance = 0;
		while (tempX != 0 || tempY != 0) {
			if (tempX % 2 != tempY % 2) {
				distance++;
			}
			tempX /= 2;
			tempY /= 2;
		}
		return distance;
	}
};

int main()
{
	Solution solution;
	int x, y;
	std::cin >> x >> y;
	std::cout << "hamming distance is " << solution.hammingDistance(x, y) << std::endl;
	system("pause");
	return 0;
}