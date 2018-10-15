using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

int main()
{
	string s;
	getline(cin, s);
    
	int n = s.size() / 4;
	cout << s.substr(0, n+1) << endl;
	for (int i = 0; i < n - 1; i++) {
		cout << s[4 * n - 1 - i];
		for (int j = 0; j < n - 1; j++)
			cout << " ";
		cout << s[n + i +1] << endl;
	}
	for (int i = 3 * n; i >= 2 * n; i--)
		cout << s[i];
}