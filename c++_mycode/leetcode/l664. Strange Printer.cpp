using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
template<typename T>
void show(vector<T> vec) {
	for (int i = 0; i != vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}
class Solution {
public:
	int strangePrinter(string s) {
		std::vector<int> x(256, -1);
		std::vector<int> pre;
		for (int i = 0; i < s.size(); i++) {
			pre.push_back(x[s[i]]);
			x[s[i]] = i;
		}
		show(pre);

		std::vector<std::vector<int>> aux(100, std::vector<int>(100, 0));
		for (int d = 0; d < s.size(); d++) {
			for (int b = 0; b < s.size() - d; b++) {
				if (d == 0) aux[b][b + d] = 1;
				else {
					int cand = aux[b][b + d - 1] + 1;
					int t = pre[b + d];
					while (t >= b) {
						cand = std::min(cand, aux[b][t] + aux[t + 1][b + d - 1]);
						t = pre[t];
					}
					aux[b][b + d] = cand;
				}
			}
		}
		return aux[0][s.size() - 1];



		if (s.size() <= 1)
			return s.size();
		string str;
		str += s[0];
		map<char, vector<int>>mp;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] != s[i - 1]) {
				str += s[i];
				mp[s[i]].push_back(i);
			}
		}
		int n = str.size();
		int start;
		set<char>::iterator it;
		vector<vector<int>>dp(n, vector<int>(n, 0));//n<=100
		for (int i = 0; i < n; ++i) {
			dp[i][i] = 1;
			for (int j = i - 1; j >= 0; --j) {
				set<char> ss;
				for (int k = j; k <= i; k++) {
					ss.insert(str[k]);
				}
				dp[j][i] = i - j + 1;
				for (it = ss.begin(); it != ss.end(); ++it) {
					start = j;
					int temp = 1;
					while (start != i + 1) {
						int idx = start;
						while (str[idx] != *it && idx != i + 1) {
							idx++;
						}
						if (idx != start) {
							temp += dp[start][idx - 1];
							start = idx;
						}
						else
							start = idx + 1;
					}
					dp[j][i] = min(dp[j][i], temp);
				}
			}
		}
		int a = 0;
		return dp[0][n - 1];

	}
};
void main()
{
	Solution a;
	cout << a.strangePrinter("abcdcacba") << endl;

}
