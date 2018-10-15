using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
int cmn(int m, int n) {
	double temp = 1;
	if (n < m - n)
		return cmn(m, m - n);
	for (int i = 0; i < m - n; ++i) {
		temp *= n + i + 1;
		temp /= i + 1;
	}
	return (int)temp;
}
string mmsort(int n, int m, int k, int flag) {
	cout << "mmsort(" << n << "," << m << "," << k << ","<<flag<<")"<<endl;
	if (k == 0)
		if (flag)	
			return string(n, 'z') + string(m, 'a');
		else
			return string(n, 'a') + string(m, 'z');
	else if (n == 0) {
		if (flag)
			return string(m, 'z');
		else
			return string(m, 'a');
	}
	else if (m == 0) {
		if (flag)
			return string(n, 'a');
		else
			return string(n, 'z');
	}
	for (int i = 0; i <= 35; i++) {
		if (k <= cmn(n, i) * cmn(m, i)) {
			return mmsort(n - i, i + 1, k / cmn(m, i) + 1, flag) + mmsort(m - i, i + 1, k % cmn(m, i), 1 - flag);
		}
		k -= cmn(n, i) * cmn(m, i);
	}
}
int main()
{
	int n, m, k;
	//cin >> n >> m >> k;
	cout << mmsort(3, 1, 1, 0) << endl;
	return 0;
}