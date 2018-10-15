#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main() {
	int n, k;
	n = 5;
	k = 2;
	long long cnt = 0;
	if (k == 0)
		cout << n * n << endl;
	for (int y = k+1; y < n; y++) {
		cnt += n / y * (y - k);
		int mod = n % y;
		if (mod > k-1)
			cnt += mod - k + 1;
	}
	cout << cnt << endl;




	return 0;
}