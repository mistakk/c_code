using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int fun(vector<int> A, int n) {
	vector<vector<int>> dp,dp2;
	dp.resize(n);
	dp2.resize(n);
	for (int i = 0; i < n; i++) {
		dp[i].resize(n);
		dp2[i].resize(n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i; j++) {
			if (i == 0) {
				dp[i + j][j] = A[j];
				dp2[i + j][j] = 0;
			}
			else
				if (A[i + j] + dp2[i + j - 1][j] > A[j] + dp2[i + j][j + 1]) {
					dp[i + j][j] = A[i + j] + dp2[i + j - 1][j];
					dp2[i + j][j] = dp[i + j -1][j + 1];
				}
				else {
					dp[i + j][j] = A[j] + dp2[i + j][j + 1];
					dp2[i + j][j] = dp[i + j ][j + 1];
				} 
		}
	}
	return dp[n - 1][0];
}
int main() {
	vector<int> A{ 1,2,100 };
	cout << fun(A, A.size()) << endl;
	return 0;
}
