using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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
	while (cin >> n >> m) {
		int index = 0, left = 0, mx = 0;
		vector<pair<int, int>> job(n + 1), guy(m);
		vector<int> record(m);

		job[0] = make_pair(0, 0);
		for (int i = 1; i < n+1; ++i) {
			cin >> job[i].first >> job[i].second;
		}


		for (int i = 0; i <= m; ++i) {
			cin >> guy[i].first;
			guy[i].second = i;  // record the sequence;
		}

		sort(job.begin(), job.end(), [&](pair<int, int> a, pair<int, int> b) {return a.first < b.first; });
		sort(guy.begin(), guy.end(), [&](pair<int, int> a, pair<int, int> b) {return a.first < b.first; });

		for (int i = 0; i < n; i++) {
			mx = max(mx, job[i].second);
			job[i].second = mx;
		}



		while (left < m && index < n + 1) {
			if (guy[left].first >= job[index].first)
				++index;
			else {
				record[guy[left].second] = job[index - 1].second;
				++left;
			}
		}

		for (int i = left; i < m; ++i) {
			record[guy[i].second] = job[n].second;
		}

		for (int i = 0; i < m; ++i) {
			cout << record[i] << endl;
		}

	}
}