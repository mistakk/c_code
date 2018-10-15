using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
#define MOD (1000000007)
long get10(int &i) {
	long res = 1;
	for (int p = 0; p < i; ++p)
		res = (res * 10) % MOD;
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<long>num(n + 1);

	for (int i = 1; i < n + 1; i++) {
		num[i] = get10(i);
		if(i>=3)
			num[i] = (num[i] + num[i - 2]) % MOD;
		for (int p = 1; p < i - 1; ++p) {
			if (p == i - 1 - p)
				num[i] = (num[i] + (num[p] * (num[p] -1) * 2) % MOD) % MOD;
			else 
				num[i] = (num[i] + (num[p] * num[i - 1 - p] * 2) % MOD) % MOD;
		}
	}
	cout << num[n] << endl;
	return 0;
}