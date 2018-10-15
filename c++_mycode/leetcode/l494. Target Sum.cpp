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
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = 0;
		for (auto a : nums)
			sum += a;
		if (sum<S || -sum>S || (sum - S) % 2)
			return 0;
		int target = (sum + S) / 2;
		vector<int>dp(target+1, 0);
		dp[0] = 1;
		for (auto n : nums) {
			for (int i = target; i >= n; i--)
				dp[i] += dp[i - n];
		}
		return dp[target];
	}
	int findTargetSumWays2(vector<int>& nums, int S) {
		long now = S;
		return helper(nums, now, 0);
	}
	int helper(vector<int>& nums, long now, int idx) {
		if (idx == nums.size()) {
			if (0 == now)
				return 1;
			return 0;
		}
		return helper(nums, now - nums[idx], idx + 1) + helper(nums, now + nums[idx], idx + 1);

	}
};
int main() {
	Solution a;
	vector<int>nums{ 1, 1, 1, 1, 1 };
	int S = 3;
	cout << a.findTargetSumWays(nums, S) << endl;
	return 0;
}