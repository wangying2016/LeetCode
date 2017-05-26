#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::max;

// my solution 1 , runtime = 6 ms
class Solution1 {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) return 0;
		auto preIt = prices.begin();
		vector<int> split;
		int profit = 0;
		for (auto curIt = prices.begin() + 1; curIt != prices.end(); ++preIt, ++curIt)
			if (*preIt > *curIt) split.push_back(preIt - prices.begin());
		if (split.size() == 0) profit = prices[prices.size() - 1] - prices[0];
		else {
			for (int i = 0; i < split.size(); ++i) {
				if (i == 0) profit += prices[split[0]] - prices[0];
				else profit += prices[split[i]] - prices[split[i - 1] + 1];
			}
			profit += prices[prices.size() - 1] - prices[split[split.size() - 1] + 1];
		}
		return profit;
	}
};

// my solution 2 , runtime = 13 ms
class Solution2 {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) return 0;
		vector<int> buy;
		vector<int> sell;
		int profit = 0;
		buy.push_back(prices[0]);
		for (auto pre = prices.begin(), cur = prices.begin() + 1; cur != prices.end(); ++pre, ++cur)
			if (*pre > *cur) {
				buy.push_back(*cur);
				sell.push_back(*pre);
			}
		sell.push_back(prices[prices.size() - 1]);
		if (buy.size() == 1 && sell.size() == 1) return prices[prices.size() - 1] - prices[0];
		for (int i = 0; i < buy.size(); ++i)
			profit += sell[i] - buy[i];
		return profit;
	}
};

// my soluiton 3 use std::queue , runtime = 6 ms
class Solution3 {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) return 0;
		int profit = 0;
		queue<int> stock;
		for (auto i : prices) {
			if (stock.empty() || stock.back() < i) {
				stock.push(i);
			}
			else {
				profit += stock.back() - stock.front();
				while (!stock.empty()) stock.pop();
				stock.push(i);
			}
		}
		profit += stock.back() - stock.front();
		return profit;
	}
};

// perfect solution tree lines code
class Solution4 {
public:
	int maxProfit(vector<int> &prices) {
		int ret = 0;
		for (size_t p = 1; p < prices.size(); ++p)
			ret += max(prices[p] - prices[p - 1], 0);
		return ret;
	}
};

int main()
{
	vector<int> prices = { 2, 4, 1, 0, 1, 0, 3 };
	Solution4 solution;
	cout << solution.maxProfit(prices) << endl;
	system("pause");
	return 0;
}