#include <iostream>
#include <string>
#include <stdlib.h>

class Solution {
public:
	std::string reverseWords(std::string s) {
		int nStartPos = 0;
		int nEndPos = 0;
		while (true) {
			nEndPos = s.find(" ", nStartPos);
			if (nEndPos == nStartPos) {
				s = s.erase(nEndPos, 1);
			} else if (nEndPos > nStartPos) {
				std::reverse(s.begin() + nStartPos, s.begin() + nEndPos);
				nStartPos = nEndPos + 1;
			} else if (nEndPos == -1) {
				std::reverse(s.begin() + nStartPos, s.end());
				break;
			}
		}
		return s;
	}
};

int main()
{
	std::string s = "wang  ying";
	Solution solution;
	std::cout << solution.reverseWords(s) << std::endl;
	system("pause");
	return 0;
}