using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <vector>
#include <unordered_set>
using namespace std;



int lcs(string s) {
	string t(s);
	reverse(t.begin(), t.end());
	int n = s.size();
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (s[i] == t[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	return n - dp[n][n];
}
int main() {
	/*while (1) {
		string s;
		cin >> s;
		if (s.size()==0)
			break;
		res.push_back(lcs(s));
		
	}*/
	string s = "xcqyk";
	cout << lcs(s) << endl;
	return 0;
}