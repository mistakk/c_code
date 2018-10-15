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




class Solution {
public:
	int minSwap(vector<int>& A, vector<int>& B) {
		int n = A.size();
		if (n == 0)
			return 0;
		int a = 0, b = 0, minval, maxval, tag0, tag1;
		int dp0 = 0, dp1 = 0, dp0_, dp1_;
		for (int i = 0; i < n; i++) {
			minval = min(A[i], B[i]);
			maxval = A[i] - minval + B[i];
			if (A[i] == B[i]) {
				tag0 = 0, tag1 = 0;
			}
			else if (A[i] < B[i]) {
				tag0 = 0, tag1 = 1;
			}
			else {
				tag0 = 1, tag1 = 0;
			}
			if (b < minval) {
				dp0_ = min(dp0, dp1) + tag0;
				dp1_ = min(dp0, dp1) + tag1;
			}
			else {
				dp0_ = dp0 + tag0;
				dp1_ = dp1 + tag1;
			}
			dp0 = dp0_, dp1 = dp1_;
			a = minval, b = maxval;
		}
		return min(dp0, dp1);
	}
};
int main() {
	long long a = 0x01234567;
	char *p = (char *)&a;
	if (*p == 0x67) {
		cout << "little" << endl;
	}
	else {
		cout << "big" << endl;
	}
	int num = 0x12345678;
	//Solution a;
	vector<int>A{ 1,3,5,4 };
	vector<int>B{ 1,2,3,7 };
	//cout << a.minSwap(A, B);
	return 0;
}













