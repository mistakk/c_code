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



class Solution {
public:
	int checkRecord(int n) {
		vector<vector<long>>dp(2, vector<long>(6, 0));
		dp[0][0] = 1;
		dp[0][1] = 1;
		dp[0][3] = 1;
		int loop = 0;
		long mod = 1000000007;
		long sumval = 3;
		for (int i = 0; i < n - 1; i++) {
			loop = 1 - loop;
			dp[loop][0] = (dp[1 - loop][0] + dp[1 - loop][1] + dp[1 - loop][2]) % mod;
			dp[loop][1] = dp[1 - loop][0];
			dp[loop][2] = dp[1 - loop][1];
			dp[loop][3] = (dp[1 - loop][0] + dp[1 - loop][1] + dp[1 - loop][2] + dp[1 - loop][3] + dp[1 - loop][4] + dp[1 - loop][5]) % mod;
			dp[loop][4] = dp[1 - loop][3];
			dp[loop][5] = dp[1 - loop][4];
		}
		return  (dp[loop][0] + dp[loop][1] + dp[loop][2] + dp[loop][3] + dp[loop][4] + dp[loop][5]) % mod;
	}
	int checkRecord2(int n) {
		int mod = 1000000007;
		vector<vector<int>>dp(2, vector<int>(6, 0));
		dp[0][0] = 1;
		dp[0][1] = 1;
		dp[0][3] = 1;
		int loop = 0;
		int sumval = 3; 
		for (int i = 0; i < n - 1; i++) {
			loop = 1 - loop;
			dp[loop][0] = (((dp[1 - loop][0] + dp[1 - loop][1]) % mod) + dp[1 - loop][2]) % mod;
			dp[loop][1] = dp[1 - loop][0];
			dp[loop][2] = dp[1 - loop][1];
			dp[loop][3] = sumval;
			dp[loop][4] = dp[1 - loop][3];
			dp[loop][5] = dp[1 - loop][4];

			sumval = (dp[loop][0] + dp[loop][1]) % mod;
			sumval = (sumval + dp[loop][2]) % mod;
			sumval = (sumval + dp[loop][3]) % mod;
			sumval = (sumval + dp[loop][4]) % mod;
			sumval = (sumval + dp[loop][5]) % mod;
		}
		return sumval;
	}
};

int main() {
	Solution a;
	cout << a.checkRecord2(100) << endl;
	return 0;
}
