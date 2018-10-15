#include <vector>
#include <iostream>
#include <map>
using namespace std;






//16.50 
class Solution {
public:
    /*
        1 <= G <= 100
        0 <= P <= 100
        1 <= group[i] <= 100
        0 <= profit[i] <= 100
        1 <= group.length = profit.length <= 100
    */
    int mod = 1e9 + 7;
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        int n = group.size();
        vector<vector<int>>dp(P + 1, vector<int>(G + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            int price = profit[i];
            int people = group[i];
            for (int p = P; p >= 0; --p) {
                for (int g = G - people; g >= 0; --g) {
                    if (p + profit[i] > P)
                        dp[P][g + people] = (dp[P][g + people] + dp[p][g]) % mod;
                    else
                        dp[p + profit[i]][g + people] = (dp[p + profit[i]][g + people] + dp[p][g]) % mod;
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= G; ++i)
            res = (res + dp[P][i]) % mod;
        return res;
    }
};

int main() {
    Solution a;
    return 0;
}