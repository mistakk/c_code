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

#include <functional>

int main() {
	int m, n;
	cin >> m >> n;
	vector<int>cost(m, 0);
	vector<int>cost2(m, 0);
	vector<int>cnt(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> cost[i];
		cost2[i] = cost[i];
		cnt[i] = 1;
	}
	map<int, vector<int>>mp;
	int key, val, maxval = 0, maxidx;
	for (int i = 0; i < n; i++) {
		cin >> key;
		cin >> val;
		mp[val-1].push_back(key);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < mp[i].size(); j++) {
			val = i;
			key = mp[i][j];
			if (cost[key] + cost2[val] > cost2[key]) {
				cost2[key] = cost[key] + cost2[val];
				cnt[key] = 1 + cnt[val];
			}
		}
		if (cost2[i] > maxval) {
			maxidx = i;
			maxval = cost2[i];
		}
	}
	cout << cnt[maxidx] << " " << maxval << endl;

	return 0;
}
