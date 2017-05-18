#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using std::vector;
using std::cout;
using std::endl;
using std::sort;
using std::priority_queue;
using std::greater;

// my solution 1 , runtime = 43 ms
class Solution1 {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int content_count = 0;
		int cookie = 0, child = 0;
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		while (true) {
			while (cookie != s.size() && child != g.size() && s[cookie] < g[child]) ++cookie;
			if (cookie < s.size() && child < g.size()) {
				++content_count;
				++cookie;
				++child;
			}
			else {
				break;
			}
		}
		return content_count;
	}
};


// my solution 2 , runtime = 46 ms
class Solution2 {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int content_count = 0;
		int cookie = 0, child = 0;
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		while (cookie < s.size() && child < g.size()) {
			while (cookie != s.size() && s[cookie] < g[child]) ++cookie;
			if (cookie < s.size()) {
				++content_count;
				++cookie;
				++child;
			}
			else {
				break;
			}
		}
		return content_count;
	}
};

// perfect solution use priority_queue , runtime = 46 ms
class Solution3 {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		priority_queue<int, vector<int>, greater<int>> priority_g(g.begin(), g.end());
		priority_queue<int, vector<int>, greater<int>> priority_s(s.begin(), s.end());
		int content_count = 0;
		while (!priority_g.empty() && !priority_s.empty()) {
			if (priority_g.top() <= priority_s.top()) {
				priority_g.pop();
				priority_s.pop();
				++content_count;
			}
			else {
				priority_s.pop();
			}
		}
		return content_count;
	}
};

int main()
{
	Solution1 solution1;
	vector<int> g = { 1, 2 };
	vector<int> s = { 1, 2, 3 };
	cout << solution1.findContentChildren(g, s) << endl;
	system("pause");
	return 0;
}