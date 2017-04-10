#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
	std::vector<std::string> fizzBuzz(int n) {
		std::vector<std::string> vecResults;
		for (int i = 1; i <= n; ++i) {
			if (i % 3 == 0 && i % 5 == 0) {
				vecResults.push_back("FizzBuzz");
			} else if (i % 3 == 0) {
				vecResults.push_back("Fizz");
			} else if (i % 5 == 0) {
				vecResults.push_back("Buzz");
			} else {
				vecResults.push_back(std::to_string(i));
			}
		}
		return vecResults;
	}
};

int main()
{
	Solution solution;
	int num = 0;
	std::cin >> num;
	std::vector<std::string> vecFizzBuzz;
	vecFizzBuzz = solution.fizzBuzz(num);
	for (auto str : vecFizzBuzz) {
		std::cout << str << std::endl;
	}
	system("pause");
	return 0;
}