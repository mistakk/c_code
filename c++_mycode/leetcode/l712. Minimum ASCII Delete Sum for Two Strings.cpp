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
//Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.
//
//Example 1:
//Input: s1 = "sea", s2 = "eat"
//	Output : 231
//	Explanation : Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
//	Deleting "t" from "eat" adds 116 to the sum.
//	At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
//	Example 2 :
//	Input : s1 = "delete", s2 = "leet"
//	Output : 403
//	Explanation : Deleting "dee" from "delete" to turn the string into "let",
//	adds 100[d] + 101[e] + 101[e] to the sum.Deleting "e" from "leet" adds 101[e] to the sum.
//	At the end, both strings are equal to "let", and the answer is 100 + 101 + 101 + 101 = 403.
////	If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
//Note:
//
//0 < s1.length, s2.length <= 1000.
//	All elements of each string will have an ASCII value in[97, 122].
class Solution {
public:
	int minimumDeleteSum(string s1, string s2) {
		int n1 = s1.size(), n2 = s2.size();
		int ret = 0;
		for (int i = 0; i < n1; i++)
			ret += s1[i];
		for (int j = 0; j < n2; j++)
			ret += s2[j];
		if (n1 == 0 || n2 == 0)
			return ret;
		vector<vector<int>>dp(n1, vector<int>(n2, 0));
		if (s1[0] == s2[0])
			dp[0][0] = s1[0];
		for (int i = 1; i < n1; i++) {
			if (s1[i] == s2[0])
				dp[i][0] = s1[i];
			else
				dp[i][0] = dp[i - 1][0];
		}
		for (int j = 1; j < n2; j++) {
			if (s1[0] == s2[j])
				dp[0][j] = s2[j];
			else
				dp[0][j] = dp[0][j - 1];
		}
		for (int i = 1; i < n1; i++) {
			for (int j = 1; j < n2; j++) {
				if (s1[i] == s2[j])
					dp[i][j] = dp[i - 1][j - 1] + s1[i];
				else
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
		return ret - 2*dp[n1 - 1][n2 - 1];
	}
};
int main() {
	Solution a;
	string s1 = "delete";
	string s2 = "leet";
	cout << a.minimumDeleteSum(s1, s2) << endl;
	return 0;
}
