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

//The length of nums is at most 20000.
//Each element nums[i] is an integer in the range[1, 10000].

class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		sort(nums.begin(), nums.end());
		int maxget = 0, maxval = 0, i, last = nums[0], dp[2] = { 0, nums[0] };
		for (i = 1; i < nums.size(); i++) {
			if (last == nums[i])
				dp[1] += nums[i];
			else {
				dp[1] += dp[0];
				dp[0] = maxval;
				maxval = max(dp[0], dp[1]); 
				if (last < nums[i] - 1) {
					maxget += maxval;
					maxval = 0;
					dp[0] = 0;
				}
				last = nums[i];
				dp[1] = last;
			}
		}
		maxval = max(maxval, dp[1] + dp[0]);
		return maxval + maxget;
	}
	int deleteAndEarn2(vector<int>& nums) {
		vector<int>cnt(10001, 0);
		int maxval = 0, i;
		vector<int>dp(2, 0);
		for (i = 0; i < nums.size(); i++)
			cnt[nums[i]]++;
		for (i = 0; i < 10001; i++) {
			dp[1] = dp[0] + cnt[i] * i;
			dp[0] = maxval;
			maxval = max(dp[0], dp[1]);
		}
		return maxval;
	}
};


int main() {
	Solution a;
	vector<int> nums{ 1,1,1,1,2,3,6,6};
	cout << a.deleteAndEarn(nums) << endl;
	return 0;
}
