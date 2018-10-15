using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define INT_MAX 0x7fffffff

#define INT_MIN 0x80000000

void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}

int climbStairs(int n) {
	if (n < 3)
		return n;
	int a = 1, b = 2;
	while (n-- > 2) {
		b += a;
		a = b - a;
	}
	return b;
}


class Solution {
public:
	//loop with mome and cut the redundant data
	int climbStairs(int n) {
		int a = 1, b = 1;
		for (int i = 2; i <= n; i++) {
			b = a + b;
			a = b - a;
		}
		return b;
	}
	//loop with memo
	int climbStairs2(int n) {
		if (n <= 2) return n;
		vector<int>dp(n + 1, 0);
		dp[1] = 1, dp[2] = 2;
		for (int i = 3; i < n; i++)
			dp[i] = dp[i - 1] + dp[i - 2];
		return dp[n];
	}
	//loop without memo
	int climbStairs3(int n) {
		if (n <= 2) return n;
		return climbStairs3(n - 1) + climbStairs3(n - 2);
	}
};

int main() {
	Solution a;
	return 0;
}