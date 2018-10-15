
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;




int main() {

	while (1) {
		char d[4] = { 'N', 'E', 'S', 'W' };
		int length, cnt = 0;
		char now;
		cin >> length;
		for (int i = 0; i < length; i++) {
			cin >> now;
			if (now == 'R') {
				cnt = (cnt + 1) % 4;
			}
			else
				cnt = (cnt + 3) % 4;
		}
		cout << d[cnt] << endl;
	}
	return 0;
}