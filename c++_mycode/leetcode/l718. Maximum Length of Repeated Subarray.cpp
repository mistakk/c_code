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


//Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
//
//Example 1:
//Input:
//  A : [1, 2, 3, 2, 1]
//	B : [3, 2, 1, 4, 7]
//	Output : 3
//	Explanation :
//	The repeated subarray with maximum length is[3, 2, 1].
//	Note :
//	1 <= len(A), len(B) <= 1000
//	0 <= A[i], B[i] < 100



class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		if (A.size() == 0 || B.size() == 0)
			return 0;
		vector<vector<int>>dp(2, vector<int>(B.size(), 0));
		for (int i = 0; i < B.size(); ++i) {
			if (A[0] == B[i])
				dp[0][i] = 1;
		}
		int loop = 0;
		int maxval = 0;
		for (int j = 1; j < A.size(); ++j) {
			loop = 1 - loop;
			if (A[j] == B[0]) 
				dp[loop][0] = 1;
			else 
				dp[loop][0] = 0;
			for (int i = 1; i < B.size(); ++i) {
				if (A[j] == B[i]) {
					dp[loop][i] = dp[1 - loop][i - 1] + 1;
					maxval = max(maxval, dp[loop][i]);
				}
				else
					dp[loop][i] = 0;
			}
		}
		return maxval;
	}

	int findLength2(vector<int>& A, vector<int>& B) {
		if (A.size() == 0 || B.size() == 0)
			return 0;
		vector<vector<int>>dp(2, vector<int>(B.size(), 0));
		int flag = 0;
		if (A[0] == B[0]) {
			dp[0][0] = 1;
			flag = 1;
		}
		for (int i = 1; i < B.size(); ++i) {
			if (A[0] == B[i])
				dp[0][i] = 1;
			else
				dp[0][i] = dp[0][i - 1];
		}
		int loop = 0;
		for (int j = 1; j < A.size(); ++j) {
			loop = 1 - loop;
			if (flag || A[j] == B[0]) {
				dp[loop][0] = 1;
				flag = 1;
			}
			else
				dp[loop][0] = 0;
			for (int i = 1; i < B.size(); ++i) {
				if (A[j] == B[i])
					dp[loop][i] = dp[1 - loop][i - 1] + 1;
				else
					dp[loop][i] = max(dp[loop][i - 1], dp[1 - loop][i]);
			}
		}
		return dp[loop][B.size() - 1];
	}
};

int main() {
	Solution a;
	vector<int> A{ 1,0,0,0,1,0,0,1,0,0 };
	vector<int> B{ 0,1,1,1,0,1,1,1,0,0 };
	cout << a.findLength(A, B) << endl;
	return 0;
}
