
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;




int main() {
	int n = 0;
	cin >> n;
	while (n--) {
		int length, cnt = 0;
		int flag = 0;
		char now;
		cin >> length;
		for (int i = 0; i < length; i++) {
			cin >> now;
			if (flag == 0 && now == '.') {
				cnt++;
				flag = 2;
			}
			else if (flag)
				flag--;
		}
		cout << cnt<<endl;
	}
	return 0;
}