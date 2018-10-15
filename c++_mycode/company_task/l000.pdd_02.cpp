using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

int check(string s) {
	if (s.size() == 1)
		return 1;
	if (s[0] == '0' &&s[s.size() - 1] == '0')
		return 0;
	if (s[0] == '0' || s[s.size() - 1] == '0')
		return 1;
	return s.size();
}
int main()
{
	string s;
	getline(cin, s);
	int n = s.size();
	int ret = 0;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n - 1; i++) {
		cout << s.substr(0, i) << endl;
		cout << check(s.substr(0, i)) << endl;
		cout << endl;
		cout << s.substr(i, n - i) << endl;
		cout << check(s.substr(i, n - i)) << endl;
		cout << endl;

		//ret += check(s.substr(0, i)) + check(s.substr(i, n - i));
	}
	cout << ret << endl;
	return ret;
}