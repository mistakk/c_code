using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>

#include <fstream>


class Solution {
public:
	vector<vector<int>> dp1;
	vector<vector<int>> dp2;
	vector<int> num;
	bool PredictTheWinner_1(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j <= n - 1; j++) {
				if (i == j)
					dp[i][j] = nums[j];
				else {
					dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
				}
			}
		}
		return dp[0][n - 1] >= 0;
	}
	bool PredictTheWinner_2(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n, 0);
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j <= n - 1; j++) {
				if (i == j)
					dp[j] = nums[j];
				else {
					dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
				}
			}
		}
		return dp[n - 1] >= 0;
	}

	bool PredictTheWinner_right(vector<int>& nums) {
		int n = nums.size();
		if (n % 2 == 0)
		{
			return true;
		}
		std::vector<int> dp(nums.size(), 0);
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i; j < n; j++)
			{
				if (i == j)
				{
					dp[j] = nums[i];
				}
				else
				{
					dp[j] = std::max(nums[i] - dp[j], nums[j] - dp[j - 1]);
				}
			}
		}
		return dp[n - 1] >= 0;
	}

	bool PredictTheWinner(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			dp1.push_back(vector<int>());
			dp2.push_back(vector<int>());
			num.push_back(nums[i]);
			for (int j = 0; j < n; j++) {
				dp1[i].push_back(-1);
				dp2[i].push_back(-1);
			}
		}
		for (int i = 0; i < n; i++) {
			dp1[i][i] = nums[i];
			dp2[i][i] = 0;
		}
		helper2(0, n - 1);
		int cn = 00;
		return dp1[0][n - 1] > dp2[0][n - 1];
	}
	int helper1(int start, int end) {
		if (dp1[start][end] != -1)
			return dp1[start][end];
		else {
			dp1[start][end] = max(num[start] + helper2(start + 1, end), num[end] + helper2(start, end - 1));
			return dp1[start][end];
		}
	}
	int helper2(int start, int end) {
		if (dp2[start][end] != -1)
			return dp2[start][end];
		else {
			dp2[start][end] = 0;
			for (int i = start; i <= end; i++)
				dp2[start][end] += num[i];
			dp2[start][end] = dp2[start][end] - helper1(start, end);
			return dp2[start][end];
		}
	}
};

int main() {
	Solution a;
	vector<int> nums{ 1, 5, 100, 7 };
	cout << a.PredictTheWinner(nums) << endl;
	return 0;
}