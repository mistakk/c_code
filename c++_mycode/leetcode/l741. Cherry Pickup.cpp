

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
	int cherryPickup2(vector<vector<int>> grid) {
		int n = grid.size(), m = 2 * n - 1;
		// t is the step, from 1 to m
		// i,p   j,q   start from 0,0  to n-1,n-1 where i+q == j+q ==t keep.
		// dp[i][j] is the sum of both path when them reach i,j, we return dp[n-1][n-1]
		// dp[i][j] = gird[i][p] + i==j? 0: gird[j][q] + max{dp[i][j], dp[i-1][j], dp[i][j-1], dp[i-1][j-1]};
		// we do not want to form lots of t, so we reuse dp;
		// but i,j is relevent with i-1 or j-1, so we cant let dp_new has influence on dp_new, we should keepi,j both from higher position
		vector<vector<int>>dp(n, vector<int>(n, -1));
		dp[0][0] = grid[0][0];
		for (int t = 1; t <= m; t++) {
			for (int i = min(n - 1, t); i >= 0; i--)
				for (int j = min(n - 1, t); j >= 0; j--) {
					int p = t - i, q = t - j;
					if (grid[i][p] == -1 || grid[j][q] == -1) {
						dp[i][j] = -1;
						continue;
					}
					if (i > 0 && j > 0)
						dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
					if (i > 0 && q > 0)
						dp[i][j] = max(dp[i][j], dp[i - 1][j]);
					if (p > 0 && j > 0)
						dp[i][j] = max(dp[i][j], dp[i][j - 1]);
					if (dp[i][j] == -1)
						continue;
					dp[i][j] += grid[i][p] + i == j ? 0 : grid[j][q];
				}
		}
		return dp[n - 1][n - 1];
	}















	int cherryPickup(vector<vector<int>> grid) {
		int N = grid.size(), M = (N << 1) - 1;
		vector<vector<int>>dp(N, vector<int>(N, 0));
		dp[0][0] = grid[0][0];

		for (int n = 1; n < M; n++) {
			for (int i = N - 1; i >= 0; i--) {
				for (int p = N - 1; p >= 0; p--) {
					int j = n - i, q = n - p;

					if (j < 0 || j >= N || q < 0 || q >= N || grid[i][j] < 0 || grid[p][q] < 0) {
						dp[i][p] = -1;
						continue;
					}

					if (i > 0)
						dp[i][p] = max(dp[i][p], dp[i - 1][p]);
					if (p > 0)
						dp[i][p] = max(dp[i][p], dp[i][p - 1]);
					if (i > 0 && p > 0)
						dp[i][p] = max(dp[i][p], dp[i - 1][p - 1]);

					if (dp[i][p] >= 0)
						dp[i][p] += grid[i][j] + (i != p ? grid[p][q] : 0);
				}
			}
		}
		return max(dp[N - 1][N - 1], 0);
	}
	int cherryPickup(vector<vector<int>> grid) {
	};

	int main() {
		Solution a;
		return 0;
	}