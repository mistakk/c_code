using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;
#include <vector>


class Solution {
public:
	int findPaths(int m, int n, int N, int i, int j) {
		int mod = 1e9 + 7;
		vector<vector<int>> dp(m, vector<int>(n, 0));
		vector<int> tempR, preR;
		int tempC, preC;
		for (int step = 0; step < N; step++) {
			for (int r = 0; r < m; r++) {
				tempR = dp[r];
				for (int c = 0; c < n; c++) {
					tempC = dp[r][c];
					dp[r][c] = (((r == 0 ? 1 : preR[c]) + (c == 0 ? 1 : preC)) % mod + ((r == m - 1 ? 1 : dp[r + 1][c]) + (c == n - 1 ? 1 : dp[r][c + 1])) % mod) % mod;
					preC = tempC;
				}
				preR = tempR;
			}
		}
		return dp[i][j];
	}
};


int main() {


	return 0;
}





