
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


bool comp2(pair<int, int> p1, pair<int, int> p2) {
	return p1.first < p2.first;
}
bool comp(int p1, int p2) {
	return p1 < p2;
}

long long cnt = 1;
void dfs(vector<int> stone, int n, long long w, int idx) {
	if (w >= 0) {
		cnt += 1;
		for (int i = idx; i < n; i++) {
			dfs(stone, n, w - stone[i], idx + 1);
		}
	}
}
int main() {
	int n, w;
	//cin >> n >> w;
	n = 1, w = 1;
	vector<int> stone(n);
	long sum = 0;
	for (int i = 0; i < n; i++) {
		//cin >> stone[i];
		stone[0] = 2;
		sum += stone[i];
	}
	if (sum <= w)
		return pow(2, n);

	for (int i = 0; i < n; i++) {
		dfs(stone, n, w - stone[i], i);
	}
	cout << cnt << endl;
	return 0;
}