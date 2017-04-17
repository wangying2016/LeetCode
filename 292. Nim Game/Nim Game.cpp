// my solution
class Solution {
public:
	bool canWinNim(int n) {
		if (n % 4 == 0) return false;
		else return true;
	}
};

// other's solution
//class Solution {
//public:
//	bool canWinNim(int n) {
//		return n % 4;
//	}
//};