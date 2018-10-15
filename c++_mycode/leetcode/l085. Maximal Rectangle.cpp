using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
		vector<vector<int>> dat;
		int m = matrix.size();
		int n = matrix[0].size();
		int ans = 0;
		vector<int> left(n, 0);
		vector<int> right(n, n);
		vector<int> height(n, 0);
		for (int i = 0; i < m; ++i) {
			int cur_left = 0, cur_right = n;
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '1')
					left[j] = max(left[j], cur_left);
				else {
					left[j] = 0;
					cur_left = j + 1;
				}
			}
			for (int j = n - 1; j >= 0; --j) {
				if (matrix[i][j] == '1')
					right[j] = min(right[j], cur_right);
				else {
					right[j] = n;
					cur_right = j;
				}
			}
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '1')
					height[j]++;
				else
					height[j] = 0;
			}
			for (int j = 0; j < n; ++j)
				ans = max(ans, height[j] * (right[j] - left[j]));

		}
		return ans;
	}
};
void main()
{
	Solution a;
	//["1", "0", "1", "0", "0"],
	//["1", "0", "1", "1", "1"],
	//["1", "1", "1", "1", "1"],
	//["1", "0", "0", "1", "0"]
	vector<vector<char>> times{ { '1','0','1','0','0' },{ '1','0','1','1','1' },{ '1','1','1','1','1' },{ '1','0','0','1','0' } };
	//vector<vector<char>> times{ { '1' } };
	cout << a.maximalRectangle(times) << endl;
}