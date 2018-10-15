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
	int maxCoinsDP(vector<int> &iNums) {
		vector<int> nums(iNums.size() + 2, 0);
		int n = 1;
		for (int x : iNums)
			if (x > 0)
				nums[n++] = x;
		nums[0] = nums[n++] = 1;
		vector<vector<int>>dp(n, vector<int>(n, 0));
		for (int k = 2; k < n; ++k) {
			for (int left = 0; left < n - k; ++left) {
				int right = left + k;
				for (int i = left + 1; i < right; ++i) {
					int maxval = nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right];
					dp[left][right] = max(dp[left][right], maxval);
				}
			}
		}

		return dp[0][n - 1];
	}
};

int main() {
	Solution a;
	vector<int> num{ 3,1,5 };
	cout << a.maxCoinsDP(num) << endl;
	return 0;

}




