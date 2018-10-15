
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool comp(pair<int, int> p1, pair<int, int> p2) {
	return p1.first < p2.first;
}
int main2() {
	int m, n;

	// n job num
	// m people num
	while (cin >> n >> m) {
		vector<pair<int, int>> job(n + 1), guy(m);
		vector<int> map(m);
		int mx = 0, idx = 0, left = 0;
		job[0] = make_pair(0, 0);
		for (int i = 1; i < n + 1; i++) {
			cin >> job[i].first >> job[i].second;
		}
		for (int i = 0; i < m; i++) {
			cin >> guy[i].first;
			guy[i].second = i; // sort destory the sequence
		}

		// sort the work, sort the guy
		sort(job.begin(), job.end(), comp);
		sort(guy.begin(), guy.end(), comp);

		for (int i = 0; i < n; i++) {
			mx = max(mx, job[i].second);
			job[i].second = mx;
		}

		while (left < m && idx < n + 1) {
			if (guy[left].first >= job[idx].first)
				idx++;
			else {
				map[guy[left].second] = job[idx - 1].second;
				left++;
			}
		}

		for (int i = left; i < m; i++) {
			map[guy[i].second] = job[n].second;
		}

		for (int i = 0; i < m; i++) {
			cout << map[i] << endl;
		}

	}
	return 0;
}









int main() {
	int n, m;
	cin >> n >> m;
	int val = 0;
	int gap = m - n + 1;
	val = (gap) / 3 * 2;
	if (gap % 3 == 0)
		return val;
	else if (gap % 3 == 1)
		if (n % 3 == 1)
			return val;
		else
			return val + 1;
	else
		if (n % 3 == 2)
			return val + 2;
		else
			return val + 1;



}