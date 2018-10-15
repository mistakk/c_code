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
#include <unordered_map>




class Solution {
public:
	static int helper(vector<int>& boxes, int n, int i, int j, int k, unordered_map<int, int> &memo) {
		if (i > j) return 0;
		int key = (i*n + j)*n + k;
		if (memo.find(key) != memo.end()) return memo[key];
		for (; i < j && boxes[i] == boxes[i + 1]; i++, k++);
		memo[key] = (k + 1)*(k + 1) + helper(boxes, n, i + 1, j, 0, memo);
		for (int m = i + 1; m <= j; m++) {
			if (boxes[i] == boxes[m])
				memo[key] = max(memo[key], helper(boxes, i + 1, n, m - 1, 0, memo) + helper(boxes, n, m, j, k + 1, memo));
		}
		return memo[key];
	}
	int removeBoxes(vector<int>& boxes) {
		int n = boxes.size();
		if (n <= 1) return n;
		unordered_map<int, int> memo;
		return helper(boxes, n, 0, n - 1, 0, memo);
	}
	int removeBoxes2(vector<int>& boxes) {
		int n = boxes.size();
		unordered_map<int, int> memo;
		return dfs(boxes, memo, n, 0, n - 1, 0);
	}
	int dfs(vector<int>&boxes, unordered_map<int, int>&memo, int n, int l, int r, int k) {
		if (l > r)return 0;
		int key = (l*n + r)*n + k;
		if (memo.find(key) != memo.end()) return memo[key];
		while (l < r && boxes[r] == boxes[r - 1]) {
			k++;
			r--;
		}
		while (l < r && boxes[l] == boxes[r]) {
			k++;
			l++;
		}
		key = (l*n + r)*n + k;
		memo[key] = (k + 1)*(k + 1) + dfs(boxes, memo, n, l, r - 1, 0);
		for (int i = l; i < r; i++) {
			if (boxes[i] == boxes[r]) {
				while (i + 1 < r && boxes[r] == boxes[i + 1])
					i++;
				memo[key] = max(memo[key], dfs(boxes, memo, n, l, i, k + 1) + dfs(boxes, memo, n, i + 1, r - 1, 0));
			}
		}
		return memo[key];
	}
	int dfs2(vector<int>& boxes, unordered_map<int, int>& memo, int n, int l, int r, int k) {
		if (l > r) return 0;
		int key = (l*n + r)*n + k;
		if (memo.find(key) != memo.end()) return memo[key];
		while (l < r && boxes[r] == boxes[r - 1]) {
			r--;
			k++;
		}
		while (l < r && boxes[l] == boxes[r]) {
			l++;
			k++;
		}

		//用map的key来代替三维数组
		key = (l*n + r)*n + k;
		memo[key] = dfs(boxes, memo, n, l, r - 1, 0) + (k + 1)*(k + 1);
		for (int i = l; i < r; i++) {
			if (boxes[i] == boxes[r]) {
				while (i + 1 < r && boxes[i + 1] == boxes[r])
					i++;
				memo[key] = max(memo[key], dfs(boxes, memo, n, l, i, k + 1) + dfs(boxes, memo, n, i + 1, r - 1, 0));
			}
		}
		return memo[key];
	}


	vector<int> data;
	vector<vector<vector<int>>>dp;
	static int helper2(vector<int>& data, int i, int j, int k, vector<vector<vector<int>>>&dp) {
		if (i > j) return 0;
		if (dp[i][j][k] != 0)
			return dp[i][j][k];
		for (; i < j && data[i] == data[i + 1]; i++, k++);

		int res = (k + 1)*(k + 1) + helper2(data, i + 1, j, 0, dp);
		for (int m = i + 1; m <= j; m++) {
			if (data[i] == data[m])
				res = max(res, helper2(data, i + 1, m - 1, 0, dp) + helper2(data, m, j, k + 1, dp));
		}
		dp[i][j][k] = res;
		return res;
	}
	static int helper(vector<int>& boxes, int n, int i, int j, int k, unordered_map<int, int> &memo) {
		if (i > j) return 0;
		int key = (i*n + j)*n + k;
		if (memo.find(key) != memo.end()) return memo[key];
		for (; i < j && boxes[i] == boxes[i + 1]; i++, k++);

		memo[key] = (k + 1)*(k + 1) + helper(boxes, n, i + 1, j, 0, memo);
		for (int m = i + 1; m <= j; m++) {
			if (boxes[i] == boxes[m])
				memo[key] = max(memo[key], helper(boxes, i + 1, n, m - 1, 0, memo) + helper(boxes, n, m, j, k + 1, memo));
		}
		return memo[key];
	}

	int removeBoxes3(vector<int>& boxes) {
		data = boxes;
		int n = boxes.size();
		if (n <= 1) return n;
		for (int i = 0; i < n; i++) {
			dp.push_back(vector<vector<int>>());
			for (int j = 0; j < n; j++) {
				dp[i].push_back(vector<int>());
				for (int k = 0; k < n; k++)
					dp[i][j].push_back(0);
			}
		}
		return helper2(boxes, 0, n - 1, 0, dp);
	}
};
int main() {
	Solution a;
	vector<int>data{ 2,2,1,2,1,1 };
	cout << a.removeBoxes3(data) << endl;
	return 0;
}