#include <iostream>
#include <string>
#include <stdlib.h>

//class Solution {
//public:
//	std::string reverseWords(std::string s) {
//		int nStartPos = 0;
//		int nEndPos = 0;
//		while (true) {
//			nEndPos = s.find(" ", nStartPos);
//			if (nEndPos == nStartPos) {
//				s = s.erase(nEndPos, 1);
//			} else if (nEndPos > nStartPos) {
//				std::reverse(s.begin() + nStartPos, s.begin() + nEndPos);
//				nStartPos = nEndPos + 1;
//			} else if (nEndPos == -1) {
//				std::reverse(s.begin() + nStartPos, s.end());
//				break;
//			}
//		}
//		return s;
//	}
//};

class Solution {
public:
	std::string reverseWords(std::string s) {
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] != ' ') {	// find first no_space item
				int j = i;
				for (; j < s.length() && s[j] != ' '; ++j){	// find first space item
					;
				}
				std::reverse(s.begin() + i, s.begin() + j);
				i = j - 1;
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