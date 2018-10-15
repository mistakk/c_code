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
	int change(int amount, vector<int>& coins) {
		vector<int>dp(amount + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < coins.size(); ++i)
			for (int j = 1; j <= amount; ++j)
				if (coins[i] <= j)
					dp[j] += dp[j - coins[i]];
		return dp[amount];
	}
};

void main()
{
	Solution a;
	vector<string> dd{ "0","0","1","1" };

}