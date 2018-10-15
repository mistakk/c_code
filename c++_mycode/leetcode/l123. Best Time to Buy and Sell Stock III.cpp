using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit3(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(2, vector<int>(n, 0));
        for (int i = 1; i < 2 + 1; i++) {
            int mincost = princes[0];
            for (int j = 1; j < n; j++) {
                mincost = min(mincost, prices[j] - dp[(i - 1) % 2][j - 1]);
                dp[i % 2][j] = max(dp[i % 2][j - 1], prices[j] - mincost);
            }
        }
        return dp[0][j];
    }
	int maxProfit1(vector<int>& prices) {
		if (prices.size() <2)
			return 0;
		int lowest = prices[0], maxv = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			lowest = min(lowest, prices[i]);
			maxv = max(maxv, prices[i] - lowest);
		}
		return maxv;
	}
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 0)
			return 0;
		int maxv = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			vector<int> temp1;
			vector<int> temp2;
			for (int j = 0; j < i; j++)
			{
				temp1.push_back(prices[j]);
			}
			for (int j = i; j < prices.size(); j++)
			{
				temp2.push_back(prices[j]);
			}
			maxv = max(maxv, maxProfit1(temp1) + maxProfit1(temp2));
		}
		return maxv;
	}
};

void main()
{
	Solution a;
	vector<int> nums{ 7, 1, 5, 3, 6, 4 };

	cout << a.maxProfit(nums) << endl;

}

