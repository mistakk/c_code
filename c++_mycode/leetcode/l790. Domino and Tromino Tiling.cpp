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

//XYZ XXZ XYY XXY XYY
//XYZ YYZ XZZ XYY XXY


class Solution {
public:
	int numTilings(int N) {
		int E = 1000000007;
		if (N < 3)
			return N;
		N -= 2;
		long a = 1, b = 1, c = 2, d = 2, e, f;
		while (N--) {
			f = (c + d)%E;
			e = (2 * b + a + c) % E;
			a = c;
			b = d;
			c = e; 
			d = f;
		}
		return e;
	}

	int numTilings2(int N) {
		int E = 1000000007;
		vector<vector<long>>dp(N + 1, { 0,0 });
		dp[1][0] = 1;
		dp[1][1] = 1;
		dp[2][0] = 2;
		dp[2][1] = 2;
		for (int i = 3; i <= N; i++)
		{
			dp[i][0] = (2 * dp[i - 2][1] + dp[i - 2][0] + dp[i - 1][0]) % E;
			dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % E;
		}
		return dp[N][0];
	}
};

int main() {
	Solution a;
	cout << a.numTilings(4) << endl;
	return 0;
}