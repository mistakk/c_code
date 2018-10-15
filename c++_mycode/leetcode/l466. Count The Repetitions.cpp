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


//Define S = [s, n] as the string S which consists of n connected strings s.For example, ["abc", 3] = "abcabcabc".
//
//On the other hand, we define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1.
//For example, ¡°abc¡± can be obtained from ¡°abdbec¡± based on our definition, but it can not be obtained from ¡°acbbe¡±.
//
//You are given two non - empty strings s1 and s2(each at most 100 characters long) and two integers 0 ¡Ü n1 ¡Ü 106 and 1 ¡Ü n2 ¡Ü 106. 
//Now consider the strings S1 and S2, where S1 = [s1, n1] and S2 = [s2, n2].Find the maximum integer M such that[S2, M] can be obtained from S1.
//
//Example:
//
//Input:
//s1 = "acb", n1 = 4
//s2 = "ab", n2 = 2
//
//Return :
//	2
pair<int, int> d[20][110];
class Solution {
public:
	int getMaxRepetitions(const string &s1, int n1, string s2, int n2) {
		if (n1 == 0 || n2 == 0 || s1.empty() || s2.empty())
			return 0;
		int len = s2.size();

		// calculate the transitions in one step
		for (int i = 0; i < len; ++i) {
			int j = i, cnt = 0;
			for (char c : s1)
				if (c == s2[j] && ++j == len) {
					cnt++;
					j = 0;
				}
			d[0][i] = { j, cnt };
		}

		// calculate the doubling table
		for (int i = 1; i < 20; ++i)
			for (int j = 0; j < len; ++j) {
				int t = d[i - 1][j].first;
				d[i][j].first = d[i - 1][t].first;
				d[i][j].second = d[i - 1][j].second + d[i - 1][t].second;
			}

		// advance n1 steps with doubling
		int cnt = 0;
		for (int i = 19, j = 0; n1 && i >= 0; --i)
			if ((1 << i) <= n1) {
				n1 -= 1 << i;
				cnt += d[i][j].second;
				j = d[i][j].first;
			}
		return cnt / n2;
	}
};
class Solution2 {
public:
	int getMaxRepetitions(string s1, int n1, string s2, int n2) {
		int source = s1.size() * n1; //10^2 * 10^6

	}
};

int main() {
	Solution a;
	return 0;
}