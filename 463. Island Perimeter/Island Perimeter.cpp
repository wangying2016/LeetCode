#include <iostream>
#include <cstdlib>
#include <vector>

using std::vector;

// my solution
class Solution {
public:
	struct point {
		unsigned x;
		unsigned y;
	};

	int validSideCount(const point &pt, vector<vector <int>> &grid) {
		int validSideCount = 0;
		if (pt.x == 0 || grid[pt.x - 1][pt.y] == 0) {
			++validSideCount;
		}
		if (pt.x == grid.size() - 1 || grid[pt.x + 1][pt.y] == 0) {
			++validSideCount;
		}
		if (pt.y == 0 || grid[pt.x][pt.y - 1] == 0) {
			++validSideCount;
		}
		if (pt.y == grid[0].size() - 1 || grid[pt.x][pt.y + 1] == 0) {
			++validSideCount;
		}
		return validSideCount;
	}

	int islandPerimeter(vector<vector<int>> &grid) {
		int islandPerimeter = 0;
		for (int row = 0; row < grid.size(); ++row) {
			for (int col = 0; col < grid[row].size(); ++col) {
				if (grid[row][col] == 1) {
					point pt = { row, col };
					islandPerimeter += validSideCount(pt, grid);
				}
			}
		}
		return islandPerimeter;
	}
};

// other's solution
//int islandPerimeter(vector<vector<int>>& grid) {
//	int count = 0, repeat = 0;
//	for (int i = 0; i < grid.size(); i++)
//	{
//		for (int j = 0; j < grid[i].size(); j++)
//		{
//			if (grid[i][j] == 1)
//			{
//				count++;
//				if (i != 0 && grid[i - 1][j] == 1) repeat++;
//				if (j != 0 && grid[i][j - 1] == 1) repeat++;
//			}
//		}
//	}
//	return 4 * count - repeat * 2;
//}

int main()
{
	Solution solution;
	vector<vector<int>> grid = { {0, 1} };
	solution.islandPerimeter(grid);
	return 0;
}