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
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>>dp(m + 1, vector<int>(n + 1));
		int cnt0, cnt1;
		for (int i = 0; i < strs.size(); ++i) {
			cnt0 = 0; cnt1 = 0;
			for (char s : strs[i])
				if (s == '0')
					cnt0++;
				else
					cnt1++;
			for (int j = m; j >= cnt0; --j)
				for (int k = n; k >= cnt1; --k)
					dp[j][k] += dp[j - cnt0][k - cnt1] + 1;
		}
		return dp[m][n];
	}
};

void main()
{
	Solution a;
	vector<string> dd{ "0","0","1","1" };

}