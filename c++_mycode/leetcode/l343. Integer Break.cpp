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
	int integerBreak(int n) {
		if (n <= 3)
			return n - 1;
		vector<int>dp(n + 1, 0);
		dp[1] = 1, dp[2] = 1;
		for (int i = 3; i <= n; ++i) {
			for (int j = 2; j >= 2, i - j >= 1; ++j) {
				dp[i] = max(dp[i], j*dp[i - j]);
				dp[i] = max(dp[i], j*(i - j));
			}
		}
		return dp[n];
	}
};

int main() {
	Solution a;
	for (int i = 2; i < 60; i++)
		cout << a.integerBreak(i) << endl;
	return 0;
}