using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>

#include <fstream>
#include <numeric>


class Solution {
public:
	int MOD = 1000000007;
	int uniqueLetterString(string S) {
		int ret = 0;
		int n = S.size();
		vector<vector<int>>mp(26, vector<int>{-1, -1});
		for (int i = 0; i < n; i++) {
			char c = S[i] - 'A';
			ret = (ret + (i - mp[c][1]) * (mp[c][1] - mp[c][0])) % MOD;
			mp[c][0] = mp[c][1];
			mp[c][1] = i;
		}
		for (int i = 0; i < 26; i++) {
			ret = (ret + (mp[i][1] - mp[i][0]) * (n - mp[i][1])) % MOD;
		}
		return ret;
	}
	int uniqueLetterString3(string S) {
		int ret = 0;
		int n = S.size();
		map<char, vector<int>>mp;
		for (int i = 0; i < n; i++)
			mp[S[i]].push_back(i);
		map<char, vector<int>>::iterator it;
		for (it = mp.begin(); it != mp.end(); it++) {
			vector<int> lis = it->second;
			int lisize = lis.size();
			if (lisize == 0)
				continue;
			else if (lisize == 1) {
				ret = (ret + (lis[0] + 1)*(n - lis[0])) % MOD;
				continue;
			}
			else
				ret = (ret + (lis[0] + 1)*(lis[1] - lis[0])) % MOD;
			for (int j = 1; j < lis.size() - 1; j++) {
				ret = (ret + (lis[j] - lis[j - 1])*(lis[j + 1] - lis[j])) % MOD;
			}
			ret = (ret + (lis[lisize - 1] - lis[lisize - 2])*(n - lis[lisize - 1])) % MOD;
		}
		return ret;
	}

	int uniqueLetterString2(string S) {
		int n = S.size();
		vector<int>dp(n, 0);
		dp[0] = 1;
		map<string, int>mp;
		for (int i = 1; i < n; i++) {
			dp[i] = dp[i - 1];
			for (int j = 0; j <= i; j++) {
				string sub = S.substr(j, i + 1 - j);
				if (mp[sub] == 0)
					mp[sub] = helper(sub);
				dp[i] = (dp[i] + mp[sub]) % MOD;
			}
		}
		return dp[n - 1];
	}
	int helper(string S) {
		map<char, int>mp;
		for (char s : S) {
			mp[s] += 1;
		}
		int ret = 0;
		for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
			if (it->second == 1)
				ret++;
		return ret;
	}
};

int main() {
	Solution a;
	string s = "ABA";
	cout << a.uniqueLetterString(s) << endl;
	return 0;
}