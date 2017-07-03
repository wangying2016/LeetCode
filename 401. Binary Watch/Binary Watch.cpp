#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <bitset>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::to_string;
using std::map;
using std::unique;
using std::sort;
using std::bitset;

// my solution 1 , runtime = 3 ms
class Solution1 {
public:
	vector<string> readBinaryWatch(int num) {
		vector<int> hour_value = { 1, 2, 4, 8 };
		vector<int> minute_value = { 1, 2, 4, 8, 16, 32 };
		vector<int> result_hour, result_minute;
		vector<string> results;
		int min_hours = num - 6 > 0 ? num - 6 : 0;
		for (int h = min_hours; h <= 4; ++h) {
			result_hour = getHour(hour_value, h);
			result_minute = getMinute(minute_value, num - h);
			sort(result_hour.begin(), result_hour.end());
			sort(result_minute.begin(), result_minute.end());
			auto last_hour = unique(result_hour.begin(), result_hour.end());
			auto last_minute = unique(result_minute.begin(), result_minute.end());
			for (auto it_hour = result_hour.begin(); it_hour != last_hour; ++it_hour) {
				for (auto it_minute = result_minute.begin(); it_minute != last_minute; ++it_minute) {
					if (*it_hour >= 0 && *it_hour <= 11 && *it_minute >= 0 && *it_minute <= 59)
					results.push_back(getTimeString(*it_hour, *it_minute));
				}
			}
		}
		return results;
	}

protected:
	vector<int> getHour(vector<int> hour_value, int h) {
		vector<int> results;
		vector<int> temp_value;
		if (h == 0) {
			results.push_back(0);
			return results;
		}
		if (h == 1) {
			for (auto i : hour_value) results.push_back(i);
			return results;
		}
		for (int i = 0; i < hour_value.size(); ++i) {
			temp_value = hour_value;
			int choose = hour_value[i];
			temp_value.erase(temp_value.begin() + i);
			vector<int> temp = getHour(temp_value, h - 1);
			for (auto j : temp) {
				int sum = 0;
				sum = j + choose;
				results.push_back(sum);
			}
		}
		return results;
	}

	vector<int> getMinute(vector<int> minute_value, int m) {
		vector<int> results;
		vector<int> temp_value;
		if (m == 0) {
			results.push_back(0);
			return results;
		}
		if (m == 1) {
			for (auto i : minute_value) results.push_back(i);
			return results;
		}
		for (int i = 0; i < minute_value.size(); ++i) {
			temp_value = minute_value;
			int choose = minute_value[i];
			temp_value.erase(temp_value.begin() + i);
			vector<int> temp = getMinute(temp_value, m - 1);
			for (auto j : temp) {
				int sum = 0;
				sum = j + choose;
				results.push_back(sum);
			}
		}
		return results;
	}

	string getTimeString(int hour, int minute) {
		return to_string(hour) + ":" + (minute >= 10 ? to_string(minute) : "0" + to_string(minute));
	}
};

// perfect solution 2 , runtime = 0 ms
class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> result;
		for (int h = 0; h < 12; ++h) {
			for (int m = 0; m < 60; ++m) {
				if (bitset<10>(h << 6 | m).count() == num)
					result.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
			}
		}
		return result;
	}
};

int main()
{
	Solution1 solution;
	solution.readBinaryWatch(2);
	system("pause");
	return 0;
}