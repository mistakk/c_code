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

int lcs(string a, string b) {
	int n1 = a.size();
	int n2 = b.size();
	vector<vector<int>> c(n1 + 1, vector<int>( n2 + 1, 0));
	for (int i = 0; i <= n1; i++) {
		for (int j = 0; j <= n2; j++) {
			if (i == 0 || j == 0) {
				c[i][j] = 0;
			}
			else if (a[i - 1] == b[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
			}
			else {
				c[i][j] = c[i][j - 1];
			}
		}
	}
	if (c[n1][n2] != n1)
		return false;
	else
		return true;
}

bool comp(vector<string> &str) {
	for (int i = 0; i < str.size(); ++i)
		for (int j = i + 1; j < str.size(); ++j) {
			if (str[i].size() != str[j].size())
				continue;
			if (lcs(str[i], str[j] + str[j]))
				return true;
			reverse(str[j].begin(), str[j].end());
			if (lcs(str[i], str[j] + str[j]))
				return true;
		}
	return false;
}
int main() {
	int n, t;
	string s;
	vector<int>sv;
	getline(cin, s);
	split(s, sv, ' ');
	n = sv[0];
	vector<bool>res(n, false);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		split(s, sv, ' ');
		t = sv[0];
		vector<string>str1(t, "");
		for (int j = 0; j < t; j++) {
			getline(cin, str1[j]);
			res[i] = comp(str1);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (res[i])
			cout << "Yeah" << endl;
		else 
			cout << "Sad" << endl;
	}
	return 0;
}