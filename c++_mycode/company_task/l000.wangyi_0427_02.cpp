#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int itoaa(string val, int &flag) {
	if (val.size() == 4 && val[1] == 'i') {
		if (val[0] == '+')
			flag = 1;
		else
			flag = -1;
		return 0;
	}
	int cnt = stoi(val);
	return cnt;
}

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> matrix(m, vector<int>(n, 0));
	vector<vector<int>> badplace(m, vector<int>(n, 0));
	string temp;
	int flag;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			flag = 0;
			int cnt = itoaa(temp, flag);
			if (flag != 0) {
				badplace[i][j] = flag;
			}
			else
				matrix[i][j] = cnt;
		}
	}
	int k;
	cout << endl; cout << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << badplace[i][j] << endl;
		}
		cout << endl;
	}
	cout << endl; cout << endl;
	cin >> k;


	vector<vector<int>> needcnt(k, vector<int>(4, 0));
	for (int i = 0; i < k; i++)
		for (int j = 0; j < 4; j++) {
			cin >> needcnt[i][j];
		}
	for (int i = 0; i < k; i++) {
		int x1 = needcnt[i][0];
		int y1 = needcnt[i][1];
		int x2 = needcnt[i][2];
		int y2 = needcnt[i][3];
		int cnt = 0;
		int flagg = 0;
		for (int x = x1; x <= x2; x++) {
			for (int y = y1; y <= y2; y++) {
				if (flagg == 0)
					if (badplace[x - 1][y - 1] == 0)
						cnt += matrix[x - 1][y - 1];
					else
						flagg = badplace[x - 1][y - 1];
				else
					if (badplace[x - 1][y - 1] * flagg == -1) {
						flagg = 10;
						break;
					}
			}
			if (flagg == 10)
				break;
		}
		if (flagg == 0)
			cout << cnt << endl;
		else if (flagg == 10)
			cout << "NAN" << endl;
		else if (flagg == 1)
			cout << "+inf" << endl;
		else
			cout << "-inf" << endl;
	}
}

