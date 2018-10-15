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
	int findIntegers(int num) {
		vector<int> dp(32, 0);
		dp[0] = 2;
		dp[1] = 3;
		for (int n = 2; n < 32; ++n) {
			dp[n] = dp[n - 1] + dp[n - 2] - 1;
		}
		int mod = 1 << 30;
		int res = 0;

		for (int i = 30; i >= 0; --i) {
			if (num / mod) {
				num = num % mod;
				mod = mod >> 1;
				if (mod!=0 && num / mod)
					return res + dp[i] + dp[i - 1] -2;
				else
					res += dp[i] - 1;
			}
			else {
				num = num % mod;
				mod = mod >> 1;
			}
		}
		return res+1;
	}
	int check(int a) {
		bool flag = false;
		int mod = 1 << 30;
		for (int i = 30; i >= 0; --i) {
			if (a / mod) {
				if (flag)
					return 0;
				else
					flag = true;
			}
			else
				flag = 0;
			a = a % mod;
			mod = mod >> 1;
		}
		return 1;
	}
};
void main()
{
	Solution a;
	int res = 0;
	for (int j = 0; j < 100; j++) {
		res = 0;
		int num = a.findIntegers(j);
		for (int i = j; i >= 0; i--)
			res += a.check(i);
		cout << "error when j = " << j << "  num = "<< num <<"  res = "<< res << endl;
	}
}
