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


int f(int n) {
	int mod = 1000000007;
	int f1 = 1;
	int f2 = f1;
	int idx = 1;
	while (n > idx) {
		if (idx == 99)
			int eee = 1;
		idx++;
		f2 = (f1 + 4 * idx - 3) % mod;
		for (int i = 2; i*i <= idx; i++) {
			if (idx % i != 0)
				continue;
			for (int j = 2; j*j <= idx; j++) {
				if (pow(j, i) <= idx) {
					f2 = (f2 + 2) % mod;
				}
				else
					break;
			}

		}
		f2 = f2 % mod;
		f1 = f2;
	}
	//cout << f2 << endl;;
	return f2;
}
int main() {
	for(int i =1;i<10;i++)
		cout << f(i) << endl;
	return 0;
}
int main2() {
	int n;
	cin >> n;
	f(n);
	return 0;
}



