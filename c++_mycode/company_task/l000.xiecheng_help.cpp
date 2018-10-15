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
#include <stdio.h>
int main()
{
	int n,temp, cnt =0;
	vector<int>vec(301, 0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (vec[temp] == 0) {
			vec[temp] = 1;
			cnt++;
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < 301; i++) {
		if (vec[i] == 1)
			cout << i << "  ";
	}
	cout << endl;
	return 0;
}

