#include <iostream>
#include <vector>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能*/
/*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */
/******************************开始写代码******************************/
int alphago(vector<int> poker) {
	int n = poker.size();
	if (n == 0)
		return 0;
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2,0)));
	for (int i = 0; i < n; i++)
		dp[i][i][0] = poker[i];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (poker[i] + dp[i + 1][j][1] > poker[j] + dp[i][j - 1][1]) {
				dp[i][j][0] = poker[i] + dp[i + 1][j][1];
				dp[i][j][1] = dp[i+1][j][0];
			}
			else {
				dp[i][j][0] = poker[j] + dp[i + 1][j][1];
				dp[i][j][1] = dp[i][j - 1][0]; 
			}
		}
	}

	if (dp[0][n - 1][0] == dp[0][n - 1][1])
		return 0;
	else if (dp[0][n - 1][0] > dp[0][n - 1][1])
		return 1;
	else 
		return 2;
}
/******************************结束写代码******************************/
int main() {
	int n;

	cin >> n;
	vector<int> poker(n);

	int num;
	for (int i = 0; i<n; ++i) {
		cin >> num;
		poker[i] = num;
	}

	int res = alphago(poker);
	cout << res << endl;
}