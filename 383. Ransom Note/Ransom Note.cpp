#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::unordered_set;

// my solution 1 use unordered_map , runtime = 35 ms
class Solution1 {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> char_count;
		for (auto c : magazine) ++char_count[c];
		for (auto c : ransomNote)
			if (char_count.find(c) == char_count.end() || char_count[c] == 0) return false;
			else --char_count[c];
			return true;
	}
};

// my solution 2 use unordered_map , runtime = 32 ms
// that std::map::operator[] returns a reference to the value
// that is mapped to a key equivalent to key, performing an 
// insertion if such key does not already exist
class Solution2 {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> char_count;
		for (auto c : magazine) ++char_count[c];
		for (auto c : ransomNote)
			if (char_count[c] == 0) return false;
			else --char_count[c];
			return true;
	}
};

// my solution 3 use two unordered_map , runtime = 36 ms
class Solution3 {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> note_map;
		unordered_map<char, int> magazine_map;
		for (auto c : ransomNote) ++note_map[c];
		for (auto c : magazine) ++magazine_map[c];
		for (auto c : note_map)
			if (magazine_map[c.first] < note_map[c.first]) return false;
		return true;
	}
};

int main()
{
	string strRansomNote = "aa";
	string strMagazines = "ab";
	Solution solution;
	cout << solution.canConstruct(strRansomNote, strMagazines) << endl;
	system("pause");
	return 0;
}