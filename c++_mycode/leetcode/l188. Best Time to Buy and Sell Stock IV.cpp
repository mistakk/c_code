using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2)
            return any_trans(prices);
        vector<vector<int>>dp(2, vector<int>(n, 0));
        for (int i = 1; i <= k; i++) {
            int mincost = prices[0];
            for (int j = 1; j < n; j++) {
                mincost = min(mincost, prices[j] - dp[(i - 1) % 2][j - 1]);
                dp[i % 2][j] = max(dp[i % 2][j - 1], prices[j] - mincost);
            }
        }
        return dp[k % 2][n - 1];
    }
    int maxProfit2(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2)
            return any_trans(prices);
        vector<vector<int>>dp(k + 1, vector<int>(n, 0));
        for (int i = 1; i <= k; i++) {
            int mincost = prices[0];
            for (int j = 1; j < n; j++) {
                mincost = min(mincost, prices[j] - dp[i - 1][j - 1]);
                dp[i][j] = max(dp[i][j - 1], prices[j] - mincost);
            }
        }
        return dp[k][n - 1];
    }
    int any_trans(vector<int>&prices) {
        int ret = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] < prices[i])
                ret += prices[i] - prices[i - 1];
        }
        return ret;
    }
};
void main()
{
    Solution a;
    vector<int>prices{ 2,4,1 };
    cout << a.maxProfit(3, prices);
}