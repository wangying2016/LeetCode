#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <utility>
#include <cmath>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::pair;
using std::pow;
using std::unordered_map;

// my solution 1 , runtime = 329 ms
class Solution1 {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int count = 0;
		for (auto cur_pt : points) {
			map<double, int> distance;
			for (auto otr_pt : points)
				if (cur_pt != otr_pt)
					distance[pow(otr_pt.first - cur_pt.first, 2) + pow(otr_pt.second - cur_pt.second, 2)]++;
			for (auto dis : distance)
				if (dis.second > 1)
					count += dis.second * (dis.second - 1);
		}
		return count;
	}
};

// perfect solution 
class Solution2 {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int booms = 0;
		for (auto &p : points) {
			unordered_map<double, int> ctr(points.size());
			for (auto &q : points)
				booms += 2 * ctr[hypot(p.first - q.first, p.second - q.second)]++;
		}
		return booms;
	}
};

int main()
{
	Solution1 solution;
	vector<pair<int, int>> points = { {0, 0}, {1, 0}, {2, 0},{1,1} };
	cout << solution.numberOfBoomerangs(points) << endl;
	system("pause");
	return 0;
}