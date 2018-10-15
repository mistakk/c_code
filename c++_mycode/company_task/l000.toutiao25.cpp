using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
int lengthOfLIS(vector<int>& nums) {
	vector<int>dp;
	dp.reserve(nums.size());
	for (auto num : nums) {
		auto it = lower_bound(dp.begin(), dp.end(), num);
		if (it == dp.end())
			dp.push_back(num);
		else
			*it = num;
	}
	return dp.size();
}
int main() {
	int n, t;
	cin >> n>>t;
	vector<int>num(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	if (t == 1) {
		cout << lengthOfLIS(num) << endl;
	}
	return 0;
}