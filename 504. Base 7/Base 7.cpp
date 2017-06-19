#include <iostream>
#include <cstdlib>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

// my solution 1 , runtime = 3 ms
class Solution1 {
public:
	string convertToBase7(int num) {
		string result;
		bool bNegative = num >= 0 ? false : true;
		do {
			result += to_string(abs(num % 7));
			num /= 7;
		} while (num);
		result += bNegative ? "-" : "";
		reverse(result.begin(), result.end());
		return result;
	}
};

int main()
{
	Solution1 solution;
	cout << solution.convertToBase7(-10) << endl;
	system("pause");
	return 0;
}