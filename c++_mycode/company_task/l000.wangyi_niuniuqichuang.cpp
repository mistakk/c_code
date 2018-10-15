
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;



bool comp(pair<int, int> a, pair<int, int>b) {
	return a.first < b.first || (a.first == b.first && a.second < b.second);
}
int main() {
	int n, time_val, hour, minn, valsum;
	cin >> n;
	vector<pair<int, int>> clock(n);
	for (int i = 0; i < n; i++) {
		cin >> clock[i].first >> clock[i].second;
	}
	cin >> time_val;
	cin >> hour >> minn;
	valsum = hour * 60 + minn;
	sort(clock.begin(), clock.end(), comp);

	for (int i = 0; i < n; i++) {
		int now_h = clock[i].first * 60 + clock[i].second + time_val;
		if (now_h > valsum) {
			cout << clock[i - 1].first << " " << clock[i - 1].second;
			return 0;
		}
			 
	}
	return 0;
}