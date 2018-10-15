using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

int main()
{
	int n, k;
	cin >> n >> k;
	vector<long> num(n, 0);
	vector<int>sleep(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> sleep[i];
	}
	long retval = 0, maxval = 0;
	for (int i = 0; i < n; i++) {
		if (sleep[i] == 1)
			maxval += num[i];
	}
	for (int i = 0; i < k; i++) {
		if (sleep[i] == 0)
			maxval += num[i];
	}
	if (k == n)
		return maxval;
	retval = maxval;
	for (int i = k; i < n; i++) {
		if (sleep[i] == 0)
			maxval += num[i];
		if (sleep[i - k] == 0)
			maxval -= num[i - k];
		retval = max(retval, maxval);
	}
	cout << retval << endl;
	return 0;
}