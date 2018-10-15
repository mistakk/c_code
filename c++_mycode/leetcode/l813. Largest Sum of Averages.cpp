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

//
//We partition a row of numbers A into at most K adjacent(non - empty) groups, then our score is the sum of the average of each group.What is the largest score we can achieve ?
//
//Note that our partition must use every number in A, and that scores are not necessarily integers.
//
//Example :
//	Input :
//	A = [9, 1, 2, 3, 9]
//	K = 3
//	Output : 20
//	Explanation :
//	The best choice is to partition A into[9], [1, 2, 3], [9].The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
//	We could have also partitioned A into[9, 1], [2], [3, 9], for example.
//	That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
//
//
//	Note :
//
//	1 <= A.length <= 100.
//	1 <= A[i] <= 10000.
//	1 <= K <= A.length.
//	Answers within 10 ^ -6 of the correct answer will be accepted as correct.
//	Seen this question in a real interview before ? YesNo

class Solution {
public:
	double largestSumOfAverages(vector<int>& A, int K) {
		int n = A.size();
		if (n == 0) return 0;
		double maxval = 0, maxtemp = 0, temp;
		vector<vector<double>>dp(n, vector<double>(n, 0));
		vector<vector<double>>dpold(n, vector<double>(n, 0));
		vector<vector<double>>dpnew(n, vector<double>(n, 0));
		for (int i = 0; i < n; i++) {
			dp[i][i] = A[i];
			for (int j = i + 1; j < n; j++) {
				dp[i][j] = (dp[i][j - 1] * (j - i) + A[j]) / (j - i + 1);
			}
		}
		dpold = dp;
		for (int k = 1; k < K; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = i; j < n; j++) {
					maxtemp = 0;
					for (int s = i; s < j; s++) {
						maxtemp = max(dpold[i][s] + dp[s + 1][j], maxtemp);
					}
					dpnew[i][j] = maxtemp;
				}
			}
			dpold = dpnew;
		}
		for (int k = 0; k < K; k++)
			maxval = max(maxval, dpold[0][n - 1]);
		return maxval;
	}
	double largestSumOfAverages2(vector<int>& A, int K) {
		int n = A.size();
		if (n == 0) return 0;
		double maxval = 0, maxtemp = 0;
		vector<vector<vector<double>>>dp2(n, vector<vector<double>>(n, vector<double>(K, 0)));
		for (int k = 0; k < K; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = i; j < n; j++) {
					if (k == 0) {
						if (j == i)
							dp2[i][i][0] = A[i];
						else
							dp2[i][j][0] = (dp2[i][j - 1][0] * (j - i) + A[j]) / (j - i + 1);
					}
					else {
						maxtemp = 0;
						for (int s = i; s < j; s++) {
							maxtemp = max(dp2[i][s][k - 1] + dp2[s + 1][j][0], maxtemp);
						}
						dp2[i][j][k] = maxtemp;
					}
				}
			}
			maxval = max(maxval, dp2[0][n - 1][k]);
		}
		return maxval;
	}
};

int main() {
	Solution a;
	vector<int> num{ 3, 9 };
	cout << a.largestSumOfAverages(num, 1) << endl;
	return 0;
}
