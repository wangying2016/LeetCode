#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>

// my solution
//class Solution {
//public:
//	std::vector<std::string> findWords(std::vector<std::string>& words) {
//		const std::set<char> setFirstLine = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', \
//											  'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p' };
//		const std::set<char> setSecondLine = { 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',		\
//											   'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l' };
//		const std::set<char> setThirdLine = { 'Z', 'X', 'C', 'V', 'B', 'N', 'M',				\
//											  'z', 'x', 'c', 'v', 'b', 'n', 'm' };
//		std::vector<std::string> vecResults;
//
//		for (auto it = words.begin(); it != words.end(); ++it) {
//			std::set<char> setThisWord;
//			if (setFirstLine.find((*it)[0]) != setFirstLine.end()) {
//				setThisWord = setFirstLine;
//			} else if (setSecondLine.find((*it)[0]) != setSecondLine.end()) {
//				setThisWord = setSecondLine;
//			} else {
//				setThisWord = setThirdLine;
//			}
//
//			bool bIsAllInOneLine = true;
//			for (size_t i = 0; i < it->length(); ++i) {
//				if (setThisWord.find((*it)[i]) == setThisWord.end()) {
//					bIsAllInOneLine = false;
//				}
//			}
//			if (bIsAllInOneLine) {
//				vecResults.push_back(*it);
//			}
//		}
//		return vecResults;
//	}
//};

// other's code
class Solution {
public:
	std::vector<std::string> findWords(std::vector<std::string>& words) {
		std::unordered_set<char> setRow1 = { 'q', 'w', 'e', 'r', 't', 'y','u', 'i', 'o', 'p' };
		std::unordered_set<char> setRow2 = { 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l' };
		std::unordered_set<char> setRow3 = { 'z', 'x', 'c', 'v', 'b' ,'n', 'm' };
		std::vector<std::unordered_set<char>> rows{ setRow1, setRow2, setRow3 };
		std::vector<std::string> vecResults;

		for (int i = 0; i < words.size(); ++i) {
			int row = 0;
			int k = 0;
			for (k = 0; k < rows.size(); ++k) {
				if (rows[k].count(tolower(words[i][0])) > 0) {
					row = k;
					break;
				}
			}
			vecResults.push_back(words[i]);

			for (size_t j = 1; j < words[i].size(); ++j) {
				if (rows[k].count(tolower(words[i][j])) == 0) {
					vecResults.pop_back();
					break;
				}
			}
		}
		return vecResults;
	}
};

int main()
{
	Solution solution;
	std::vector<std::string> vecTestData;
	std::string strData;
	while (std::cin >> strData) {
		vecTestData.push_back(strData);
	}
	std::vector<std::string> vecResults;
	vecResults = solution.findWords(vecTestData);
	for (auto it = vecResults.cbegin(); it != vecResults.cend(); ++it) {
		std::cout << *it << std::endl;
	}
	system("pause");
	return 0;
}