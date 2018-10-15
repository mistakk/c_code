using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
class Solution {
public:
	int numberOfArithmeticSlices2(vector<int>& A) {
		if (A.size() < 3)
			return 0;
		bool flag = false;
		int val = 2;
		int ret_val = 0;
		for (int i = 0; i < A.size() - 2; i++) {
			if (!flag) {
				if (A[i + 2] - A[i + 1] == A[i + 1] - A[i]) {
					flag = true;
					val += 1;
				}
			}
			else {
				if (A[i + 2] - A[i + 1] == A[i + 1] - A[i])
					val++;
				else {
					flag = false;
					ret_val += (val - 1)*(val - 2) / 2;
					val = 2;
				}
			}
		}
		if (val > 2)
			ret_val += (val - 1)*(val - 2) / 2;
		return ret_val;
	}
	int numberOfArithmeticSlices(vector<int>& A) {
		int n = A.size();
		int res = 0;
		if (n < 3)
			return 0;
		vector<int> dp(n, 0);
		for (int i = 2; i < n; i++)
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
				dp[i] = dp[i - 1] + 1;
				res += dp[i];
			}
		return res;
	}
};
void main()
{
	Solution a;
	vector<int> x{ 1,2,3,4,5,6 };
	int xx = a.numberOfArithmeticSlices(x);
	cout << xx << endl;

}
