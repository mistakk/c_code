#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
int main() {
	int n, temp, big = 0, les = 0, res = 0;
	//cin >> n;//注意while处理多个case
	vector<int> init{ -10,16,5,4,-16,4,-2,-1 };
	n = init.size();
	for (int i = 0; i < n; i++) {
		//cin >> init[i];
		;
	}
	for (int i = 0; i < n; i++) {
		//cin >> temp;
		//init[i] -= temp;
		;
	}
	int tt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (init[i] >= 0) {
			res = res + big + les;
			big += init[i];
		}
		else {
			res = res + big + les;
			big += init[i];
			if (big < 0) {
				les -= big;
				big = 0;
			}
		}
	}
	cout << res << endl;
	return 0;
}