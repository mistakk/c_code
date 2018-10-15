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

#include <functional>


class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int>dp;
		dp.reserve(nums.size());

		
			int a = 1;
		
			int b = a + 1;

		for (auto num : nums) {
			auto it = lower_bound(dp.begin(), dp.end(), num);
			if (it == dp.end())
				dp.push_back(num);
			else
				*it = num;
		}
		return dp.size();
	}
	int lengthOfLIS2(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		vector<int> dp(n, 1);
		int ret = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++)
				if (nums[j] < nums[i])
					dp[i] = max(dp[i], dp[j] + 1);
			ret = max(ret, dp[i]);
		}
		return ret;
	}
};
int main() {
	Solution a;
	vector<int>nums{ 10,9,2,5,3,7,101,18 };
	cout << a.lengthOfLIS(nums) << endl;
	return 0;
}
