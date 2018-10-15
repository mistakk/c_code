#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;
bool cmp(const pair<int, int>&a, const pair<int, int>&b) {
	return a.second > b.second;
}
int main() {
	int n, m, k, C;
	string ss;
	ifstream fin("C:\\Users\\sheldonxxie\\leetcode\\in3.txt");
	int i, j, temp, tempval;
	fin >> ss;
	n = atoi(ss.c_str());
	fin >> ss;
	m = atoi(ss.c_str());
	fin >> ss;
	k = atoi(ss.c_str());
	fin >> ss;
	C = atoi(ss.c_str());
	//cin >> n >> m >> k >> C;

	vector<int>rank(n, 0);
	vector<int>weight(m, 0);

	vector<pair<int, int>>valend;

	int flag = -1;
	int thisisbad = 0;
	for (j = 0; j < m; j++) {
		fin >> ss;
		weight[j] = atoi(ss.c_str());
	}
	int best = 0;
	for (i = 0; i < n; i++) {
		tempval = 0;

		for (j = 0; j < m; j++) {
			fin >> ss;
			temp = atoi(ss.c_str());

			if (temp == -1) {
				flag = i;
				temp = 0;
				best = C * weight[j];
				thisisbad = 1;
			}
			tempval += temp * weight[j];
		}
		if (thisisbad == 1) {
			best += tempval;
			thisisbad = 0;
		}

		valend.push_back(make_pair<>(i, tempval));
	}


	vector<int> allval;
	for (int ii = 0; ii < n; ii++)
		allval.push_back(valend[ii].second);
	i = 0;
	int start = 0;
	int val_3_last = -1, cnt_3_last = 0;
	int val_2_last = -1;
	while (i < n) {
		int idx = valend[i].first;
		int val = valend[i].second;
		while (i < n - 1 && val == valend[i + 1].second) {
			i++;
		}
		if (i < k) {
			cnt_3_last += i - start + 1;
			val_3_last = valend[start].second;
			for (int j = start; j <= i; j++)
				rank[j] = 1;
		}
		else if (start < k) {
			val_2_last = valend[start].second;
			for (int j = start; j <= i; j++)
				rank[j] = 3;
		}
		else {
			for (int j = start; j <= i; j++)
				rank[j] = 2;
		}
		i += 1;
		start = i;
	}

	cout << "best:" << best << endl;
	cout << "val_3_last:" << val_3_last << endl;
	cout << "cnt_3_last:" << cnt_3_last << endl;
	cout << "val_2_last:" << val_2_last << endl;
	cout << endl;
	cout << "rank:" << endl << endl;

	cout << "idx:::" << endl;
	for (i = 0; i < n; i++)
		cout << (i + 1) % 10 << "  ";
	cout << endl;

	cout << "处理-1之前" << endl;
	for (i = 0; i < n; i++)
		cout << rank[i] << "  ";
	cout << endl;
	cout << endl;
	cout << "best:" << best << endl;
	cout << "val_3_last:" << val_3_last << endl;
	cout << "cnt_3_last:" << cnt_3_last << endl;
	cout << "k:" << k << endl;
	if (rank[flag] != 1) {
		if (best >= val_3_last && val_3_last > 0) {
			if (cnt_3_last == k) {
				for (i = 0; i < n; i++) {
					if (valend[i].second == val_3_last)
						rank[valend[i].first] = 3;
				}
			}
			rank[flag] = 3;
		}
		else if (best >= val_2_last && val_2_last > 0) {
			rank[flag] = 3;
		}
	}
	cout << "处理-1之后" << endl;
	for (i = 0; i < n; i++)
		cout << rank[i] << "  ";
	cout << endl;
	return 0;
}