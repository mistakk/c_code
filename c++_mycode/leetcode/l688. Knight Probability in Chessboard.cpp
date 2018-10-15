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
	double helper(vector<vector<vector<double>>>&dp, int N, int K, int r, int c) {
		if (r >= N || r < 0 || c >= N || c < 0)
			return 0;
		if (K == 0)
			return 1;
		if (dp[r][c][K] != 0)
			return dp[r][c][K];
		else {
			double res = 0;
			res += helper(dp, N, K - 1, r - 1, c - 2);
			res += helper(dp, N, K - 1, r - 1, c + 2);
			res += helper(dp, N, K - 1, r + 1, c - 2);
			res += helper(dp, N, K - 1, r + 1, c + 2);
			res += helper(dp, N, K - 1, r - 2, c - 1);
			res += helper(dp, N, K - 1, r - 2, c + 1);
			res += helper(dp, N, K - 1, r + 2, c - 1);
			res += helper(dp, N, K - 1, r + 2, c + 1);
			dp[r][c][K] = res / 8;
			return dp[r][c][K];
		}
	}
	double knightProbability(int N, int K, int r, int c) {
		vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(K+1,0)));
		return helper(dp, N, K, r, c);
	}
};


int main() {
	Solution a;
	cout << a.knightProbability(3, 2, 0, 0) << endl;

	return 0;
}