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
#include <iomanip>

int main() {
    int m, a, r;
    cin >> m >> a >> r;
    // 1 - r            
    // no more than m   
    // reach a stop     
    double res = 0;
    if (a == 0 || r + a <= m + 1) {
        res = 0;
    }
    else {
        vector<double>dp(a + r, 0);
        dp[0] = 1;
        for (int i = 0; i < a; i++) {
            for (int j = 1; j <= r; j++) {
                dp[i + j] += dp[i] / r;
            }
            dp[i] = 0;
        }
        for (int i = m + 1; i < r + a; i++)
            res += dp[i];
    }

    cout << setiosflags(ios::fixed) << setprecision(5);
    cout << 1 - res;
    return 0;
}