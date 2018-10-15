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
void split(const string& s, vector<int>& sv, const char flag = ' ') {
	sv.clear();
	istringstream iss(s);
	string temp;

	while (getline(iss, temp, flag)) {
		sv.push_back(stoi(temp));
	}
	return;
}
int main()
{
	int n, m;
	string s;
	vector<int>sv;
	getline(cin, s);
	split(s, sv, ' ');
	n = sv[0];
	m = sv[1];
	vector<vector<int>>num(n, vector<int>(n, 0));
	set<int> setm;
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		split(s, sv, ' ');
		for (auto j : sv) {
			num[i][j] = 1;
			num[j][i] = 1;
		}
		if (i == m) {
			for (auto j : sv)
				setm.insert(j);
		}
	}
	int score = -1, best = -1, score_now;
	for (int i = 0; i < n; i++) {
		if (i == m)
			continue;
		if (find(setm.begin(), setm.end(), i) != setm.end())
			continue;
		score_now = 0;
		for (int j = 0; j < n; j++) {
			if (num[i][j] == 1)
				if (find(setm.begin(), setm.end(), j) != setm.end())
					score_now += 1;
		}
		if (score_now > score) {
			best = i;
			score = score_now;
		}
	}
	cout << best << endl;
	return 0;
}