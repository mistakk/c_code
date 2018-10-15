using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>


class Solution {
public:

    int racecar2(int target) {
        set<int>se;
        queue<int>q;//x * MOD + y          
        q.push(1);
        int MOD = 1000;
        int period = 0;
        int pos, spd;
        while (!q.empty()) {
            int cnt = q.size();
            while (cnt--) {
                int pos_spd = q.front(); q.pop();
                if (pos_spd%MOD >= MOD / 2) {
                    pos = pos_spd / MOD + 1;
                    spd = pos_spd % MOD - MOD;
                }
                else {
                    pos = pos_spd / MOD;
                    spd = pos_spd % MOD;
                }
                if (pos == target)
                    return period;
                else {
                    int posa = pos;
                    int spda = spd;
                    int sign = 1;
                    if (spd < 0)
                        sign = -1;

                    posa += sign * pow(2, sign * (spd - sign));
                    spda = spd + sign;

                    if (find(se.begin(), se.end(), posa * MOD + spda) == se.end()) {
                        se.insert(posa * MOD + spda);
                        q.push(posa * MOD + spda);
                    }

                    int posb = pos;
                    int spdb = -1 * sign;
                    if (find(se.begin(), se.end(), posb * MOD + spdb) == se.end()) {
                        se.insert(posb * MOD + spdb);
                        q.push(posb * MOD + spdb);
                    }
                }
            }
            period += 1;
        }
        return 0;
    }
    int dp[10001];
    int racecar(int target) {
        if (dp[target] > 0) return dp[target];
        int n = floor(log2(target)) + 1;
        if (1 << n == target + 1)
            dp[target] = n;
        else {
            dp[target] = racecar((1 << n) - 1 - target) + n + 1;  //go a for n times, to get (1<<n) -1, then reverse;  go n+1 times, need (1<<n-1)
            for (int m = 0; m < n - 1; ++m) {
                dp[target] = min(dp[target], racecar(target - (1 << (n - 1)) + (1 << m)) + 1 + m + n);
            }
        }
        return dp[target];
    }
};

void main()
{
    Solution a;
    cout << a.racecar(4) << endl;

}
