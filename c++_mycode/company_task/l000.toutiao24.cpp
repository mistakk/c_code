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
long check()
int main() {
	int n, m;
	string s;
	vector<int>sv;
	getline(cin, s);
	split(s, sv, ' ');
	n = sv[0];
	m = sv[1];
	map<string, long>mp;
	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		split(s, sv, ' ');

	}
}