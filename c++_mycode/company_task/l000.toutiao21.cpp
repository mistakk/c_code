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
int findf(vector<int> &father, int x) {
	if (father[x] != x)
		father[x] = findf(father, father[x]);
	return father[x];
}
void unionp(vector<int> &father, int a, int b) {
	int pa = findf(father, a);
	int pb = findf(father, b);
	if (pa != pb ) {
		father[pb] = pa;
	}
}
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
	int n;
	string s;
	vector<int>sv;
	getline(cin, s);
	split(s, sv, ' ');
	n = sv[0];
	vector<int> father(n + 1);
	for (int i = 1; i < n + 1; i++) { // 1...10
		father[i] = i;
	}
	for (int i = 1; i < n + 1; i++) {
		getline(cin, s);
		split(s, sv, ' ');
		for (int j = 0; j < sv.size() - 1; j++) {
			unionp(father, i, sv[j]);
		}
	}
	set<int>cnt;
	for (int i = 1; i < n + 1; i++) { // 1...10
		findf(father, i);
		cnt.insert(father[i]);
	}
	cout << cnt.size() << endl;
}
