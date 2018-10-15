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

    int findRotateSteps2(string ring, string key) {
        int n = ring.length();
        int m = key.length();
        vector<vector<int>>dp(m + 1, vector<int>(n , 0));
        //Start by solving key[i:m-1] -> smallest instance is key[m-1:m-1]
        for (int i = m - 1; i >= 0; i--) {
            //Solve the problem for key[i:m-1] and when the ring arrow points at index j.
            for (int j = 0; j < n; j++) {
                dp[i][j] = INT_MAX;
                //Try out every type of spin (by 0, 1, 2, 3, and choose the best choice)
                for (int k = 0; k < n; k++) {
                    if (ring[k] == key[i]) {
                        //Using greedy logic that we should just use the min spin 
                        int diff = abs(j - k);
                        //Choose the min of moving clockwise or counterclockwise
                        int step = min(diff, n - diff);
                        //dp[i+1][k] = Solve the subproblem from key[i+1: m-1] and while our pointer points to k now since
                        //we have rotated the dial there.
                        dp[i][j] = min(dp[i][j], step + dp[i + 1][k]);
                    }
                }
            }
        }

        return dp[0][0] + m; //We will press the dial button m times in total no matter what.
    }

    int findRotateSteps(string ring, string key) {
        int k = key.size();
        int r = ring.size();
        vector<vector<int>>dp(k + 1, vector<int>(r, 0));
        //从最后一个位置看，是随意的；从第一个位置看，是固定的
        //dp[i][j] 处于第j个位置时, 还有i个没处理完, 此时已经走过的步数
        for (int i = k - 1; i >= 0; --i) {
            for (int j = 0; j < r; ++j) {
                dp[i][j] = INT_MAX;
                for (int p = 0; p < r; ++p) {
                    if (ring[p] == key[i]) {
                        int diff = abs(j-p);
                        int step = min(diff, r - diff);
                        dp[i][j] = min(dp[i][j], step + dp[i + 1][p]);
                    }
                }
            }
        }
        //从最后一个位置看，是随意的；从第一个位置看，是固定的
        return dp[0][0] + k;
    }
};
void main()
{
    string ring = "godding";
    string key = "gd";
    Solution a;

    cout << a.findRotateSteps(ring, key);


}