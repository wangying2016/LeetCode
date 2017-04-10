#include <iostream>
#include <string>
#include <stdlib.h>

// my first solution
//class Solution {
//public:
//	std::string reverseString(std::string s) {
//		auto itPre = s.begin();
//		auto itBack = s.end() - 1;
//		for (; itPre < itBack; ++itPre, --itBack) {
//			char temp = *itPre;
//			*itPre = *itBack;
//			*itBack = temp;
//		}
//		return s;
//	}
//};

// my second solution
//class Solution {
//public:
//	std::string reverseString(std::string s) {
//		std::reverse(std::begin(), std::end());
//		return s;
//	}
//};

// perfect solution
class Solution {
public:
	std::string reverseString(std::string s) {
		int i = 0, j = s.size() - 1;
		while (i < j) {
			std::swap(s[i++], s[j--]);
		}
		return s;
	}
};

int main()
{
	Solution solution;
	std::string strData;
	std::cin >> strData;
	std::cout << "Reverse String is " << solution.reverseString(strData)
		<< std::endl;
	system("pause");
	return 0;
}