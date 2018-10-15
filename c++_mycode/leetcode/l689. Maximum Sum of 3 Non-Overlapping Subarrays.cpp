using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int m = 3;
        vector<int>presum(n + 1, 0);
        vector<vector<int>>path(m + 1, vector<int>(n + 1));
        vector<vector<int>>dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++)
            presum[i] = nums[i - 1] + presum[i - 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = k; j <= n; ++j) {
                int include = presum[j] - presum[j - k] + dp[i - 1][j - k];
                int exclude = dp[i][j - 1];
                if (include > exclude) {
                    dp[i][j] = include;
                    path[i][j] = j - k;
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                    path[i][j] = path[i][j - 1];
                }
            }
        }
        vector<int>res(m, 0);
        res[m - 1] = path[m][n];
        for (int i = m - 2; i >= 0; --i)
            res[i] = path[i + 1][res[i + 1]];
        return res;
    }
    vector<int> maxSumOfThreeSubarrays3(vector<int>& nums, int k) {
        int n = nums.size();
        int m = 3;
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>>path(m + 1, vector<int>(n + 1, 0));
        vector<int>prefixsum(n + 1, 0);//sum of all nums minus than i

        int s = 0;
        for (int i = 1; i < n + 1; ++i) {
            s += nums[i - 1];
            prefixsum[i] = s;
        }
        int include, exclude;
        for (int i = 1; i < m + 1; ++i) {   //i : 1 to 3
            for (int j = k; j < n + 1; ++j) {   //j : k to n
                include = prefixsum[j] - prefixsum[j - k] + dp[i - 1][j - k];
                exclude = dp[i][j - 1];
                if (include > exclude) {
                    dp[i][j] = include;
                    path[i][j] = j - k;
                }
                else {
                    dp[i][j] = exclude;
                    path[i][j] = path[i][j - 1];
                }
            }
        }
        vector<int>res(m, 0);
        res[m - 1] = path[m][n];
        for (int i = m - 2; i >= 0; --i) {
            res[i] = path[i + 1][res[i + 1]];
        }
        /*res[2] = path[3][n];
        res[1] = path[2][res[2]];
        res[0] = path[1][res[1]];*/

        return res;
    }
    vector<int> maxSumOfThreeSubarrays2(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>sums(n, 0);
        vector<vector<int>>dp1(n, vector<int>(2, 0));
        vector<vector<int>>dp2(n, vector<int>(3, k - 1));
        vector<vector<int>>dp3(n, vector<int>(3, k - 1));
        //0 is maxval to now  -1 is  maxval idx  -2 is last maxval idx
        int sumk = 0;
        for (int i = 0; i < k; ++i)
            sumk += nums[i];
        sums[k - 1] = sumk;
        dp1[k - 1][0] = sumk;
        dp1[k - 1][1] = k - 1;
        for (int i = k; i < n; ++i) {
            sumk = sumk + nums[i] - nums[i - k];
            sums[i] = sumk;
            dp1[i][0] = max(dp1[i - 1][0], sumk);
            dp1[i][1] = dp1[i][0] > dp1[i - 1][0] ? i : dp1[i - 1][1];
        }
        for (int i = 2 * k - 1; i < n; ++i) {
            dp2[i][0] = max(dp2[i - 1][0], dp1[i - k][0] + sums[i]);
            dp2[i][1] = dp2[i][0] > dp2[i - 1][0] ? dp1[i - k][1] : dp2[i - 1][1];
            dp2[i][2] = dp2[i][0] > dp2[i - 1][0] ? i : dp2[i - 1][2];
        }
        for (int i = 3 * k - 1; i < n; ++i) {
            dp3[i][0] = max(dp3[i - 1][0], dp2[i - k][0] + sums[i]);
            dp3[i][1] = dp3[i][0] > dp3[i - 1][0] ? dp2[i - k][2] : dp3[i - 1][1];
            dp3[i][2] = dp3[i][0] > dp3[i - 1][0] ? i : dp3[i - 1][2];
        }
        int third = dp3[n - 1][2];
        int second = dp3[third][1];
        int first = dp2[second][1];
        return { first - k + 1,second - k + 1,third - k + 1 };
    }
};
void main()
{
    Solution a;
    vector<int>nums{ 7,13,20,19,19,2,10,1,1,19 };
    vector<int>prices = a.maxSumOfThreeSubarrays(nums, 3);
    for (int i = 0; i < prices.size(); ++i)
        cout << prices[i] << endl;
}