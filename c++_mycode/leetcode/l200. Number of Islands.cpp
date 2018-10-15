using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>

#include <fstream>
#include <numeric>


class Solution {
public:
	int count;
	vector<int>father;
	int numIslands(vector<vector<char>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		if (n == 0 || m == 0)
			return 0;
		count = 0;
		father.resize(m*n, 0);
		vector<int>di{ -1,0,0,1 };
		vector<int>dj{ 0,-1,1,0 };
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
				if (grid[i][j] == '1') {
					father[i*m + j] = i * m + j;
					count++;
				}
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == '1')
					for (int k = 0; k < 4; k++) {
						int ni = i + di[k];
						int nj = j + dj[k];
						if ((ni >= 0) && (ni < n) && (nj >= 0) && (nj < m) && (grid[ni][nj] == '1'))
							unionp(i*m + j, ni*m + nj);
					}
			}
		return count;
	}
	int findp(int x) {
		//return the root of point x
		if (father[x] != x)
			father[x] = findp(father[x]);
		return father[x];
	}
	void unionp(int x, int y) {
		//px is the root of x, py is the root of y
		//make py is the root of px
		int px = findp(x);
		int py = findp(y);
		if (px != py) {
			father[px] = py;
			count--;
		}
	}
};
int main() {
	Solution a;
	vector<vector<char>> grid{ { '1' } };
	cout << a.numIslands(grid) << endl;
	cout << sizeof(void*) << endl;
	return 0;
}
